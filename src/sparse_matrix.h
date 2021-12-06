//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <string>
#include <vector>
#include <unordered_map>
#include <functional> //std::hash
//---------------------------------------------------------------------------


/*
template<typename T>
class t_matrix
{
  public:

  unordered_map  
};
//---------------------------------------------------------------------------
*/




class t_matrix;

class t_final_proxy
{
public:
  t_final_proxy(t_matrix* aParent, size_t anIndex1, size_t anIndex2);


  // принимаем int:
  t_final_proxy& operator = (const int& anSrc);

  // приводимся к int:
  operator int() const;

  t_matrix* m_Parent;
  size_t m_nIndex1;
  size_t m_nIndex2;

};



class t_proxy_arr
{
public:
  //t_proxy_arr();
  t_proxy_arr(t_matrix* aParent, size_t anIndex1);


  t_final_proxy operator[](size_t anIndex2) {
    return t_final_proxy(m_Parent, m_nIndex1, anIndex2);
  };

  t_matrix* m_Parent;
  size_t m_nIndex1;
};



struct t_pair
{
  size_t m_n1;
  size_t m_n2;

  // не нужен похоже для pod типов
  bool operator == (const t_pair& rhs) const {
    return (m_n1 == rhs.m_n1 && m_n2 == rhs.m_n2);
  }

};


class t_matrix
{
public:


  t_matrix(int an_def_value)
    : m_n_def_value(an_def_value) {};

  // доступ по скобочкам
  t_proxy_arr operator[](size_t anIndex1) 
  {
    //t_proxy_arr var;
    //var.m_Parent = this;

    //return t_proxy_arr {this, 1};
    return t_proxy_arr{this, anIndex1 };
    //return 10;
  };



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

  void set_value(size_t anIndex1, size_t anIndex2, int anValue) {

    // если проставляют дефолтное значение, значит удаляем запись:
    if (anValue == m_n_def_value) {
      m_map.erase(t_pair{ anIndex1, anIndex2 });
      return;
    }

    // в других случаях или создаём или обновляем:
    m_map[t_pair{ anIndex1, anIndex2 }] = anValue;

    //auto var = m_map.insert(std::make_pair(t_pair{ anIndex1, anIndex2 }, anSrc));
  }

  int get_value(size_t anIndex1, size_t anIndex2) const {

    auto iter = m_map.find(t_pair{ anIndex1, anIndex2 });
    if (iter == m_map.end()) {
      return m_n_def_value;
    }

    return iter->second;
  }

private:


  //typedef std::pair<int, int> t_pair;
  
  // custom hash can be a standalone function object:
  struct MyHash
  {
    std::size_t operator()(t_pair const& s) const noexcept
    {
      std::size_t h1 = std::hash<int>{}(s.m_n1);
      std::size_t h2 = std::hash<int>{}(s.m_n2);
      return h1 ^ (h2 << 1); // some mix of hashes
    }
  };

  std::unordered_map<t_pair, int, MyHash> m_map;
  int m_n_def_value;
};
