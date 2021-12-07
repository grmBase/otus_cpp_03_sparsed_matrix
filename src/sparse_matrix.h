//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <string>
#include <unordered_map>
#include <functional> //std::hash
//---------------------------------------------------------------------------




// Forward declaration
template <typename T, T a_def_value>
class t_matrix;


template <typename T, T a_def_value>
class t_final_proxy
{
public:

  t_final_proxy(t_matrix<T, a_def_value>* aParent, size_t anIndex1, size_t anIndex2)
    :m_Parent(aParent),
    m_nIndex1(anIndex1),
    m_nIndex2(anIndex2)
  {};


  // принимаем int:
  t_final_proxy& operator = (const int& anSrc)
  {
    m_Parent->set_value(m_nIndex1, m_nIndex2, anSrc);

    return *this;
  };



  // приводимся к int:
  operator T() const
  {
    return m_Parent->get_value(m_nIndex1, m_nIndex2);
  };

  t_matrix<T, a_def_value>* m_Parent;
  size_t m_nIndex1;
  size_t m_nIndex2;
};
//---------------------------------------------------------------------------


template <typename T, T a_def_value>
class t_proxy_arr
{
public:

  //t_proxy_arr();
  t_proxy_arr(t_matrix<T, a_def_value>* aParent, size_t anIndex1)
    :m_Parent(aParent),
    m_nIndex1(anIndex1)
  {};


  t_final_proxy<T, a_def_value> operator[](size_t anIndex2) {
    return t_final_proxy(m_Parent, m_nIndex1, anIndex2);
  };

  t_matrix<T, a_def_value>* m_Parent;
  size_t m_nIndex1;
};
//---------------------------------------------------------------------------


struct t_pair
{
  size_t m_n1;
  size_t m_n2;

  // не нужен похоже для pod типов
  bool operator == (const t_pair& rhs) const {
    return (m_n1 == rhs.m_n1 && m_n2 == rhs.m_n2);
  }

};
//---------------------------------------------------------------------------



template <typename T, T a_def_value>
class t_matrix
{

public:

  t_matrix() {};

  // доступ по скобочкам
  t_proxy_arr<T, a_def_value> operator[](size_t anIndex1) 
  {
    //t_proxy_arr var;
    //var.m_Parent = this;

    //return t_proxy_arr {this, 1};
    return t_proxy_arr{this, anIndex1};
    //return 10;
  };





  /*
  // Свой итератор, чтобы для него сделать оператор преобрзования в tuple
  class t_my_iterator
  {

  public:

    t_my_iterator(t_node_record* apNode) : m_pNode(apNode) { };

    t_my_iterator& operator++ () {
      if (!m_pNode) {
        throw std::runtime_error("next it nullptr");
        //return *this;
      }
      m_pNode = m_pNode->p_next;

      return *this;
    };

    bool operator!= (const t_my_iterator& other)
    {
      return m_pNode != other.m_pNode;
    }

    const T& operator*() const
    {
      return m_pNode->m_date;
    }


  private:

    t_node_record* m_pNode;
  };
  */



  // для перебора range for:
  auto begin() const {
    return m_map.begin();
  }

  auto end() const {
    return m_map.end();
  }


  //operator std::tuple<const t_pair, int>();

  size_t size() const
  {
    return m_map.size();
  };





  void set_value(size_t anIndex1, size_t anIndex2, T anValue) {

    // если проставляют дефолтное значение, значит удаляем запись:
    if (anValue == a_def_value) {
      m_map.erase(t_pair{ anIndex1, anIndex2 });
      return;
    }

    // в других случаях или создаём или обновляем:
    m_map[t_pair{ anIndex1, anIndex2 }] = anValue;

    //auto var = m_map.insert(std::make_pair(t_pair{ anIndex1, anIndex2 }, anSrc));
  }

  T get_value(size_t anIndex1, size_t anIndex2) const {

    auto iter = m_map.find(t_pair{ anIndex1, anIndex2 });
    if (iter == m_map.end()) {
      return a_def_value;
    }

    return iter->second;
  }

private:


  // custom hash can be a standalone function object:
  struct MyHash
  {
    std::size_t operator()(t_pair const& s) const noexcept
    {
      std::size_t h1 = std::hash<T>{}(s.m_n1);
      std::size_t h2 = std::hash<T>{}(s.m_n2);
      return h1 ^ (h2 << 1); // some mix of hashes
    }
  };

  std::unordered_map<t_pair, T, MyHash> m_map;

};
