//---------------------------------------------------------------------------
#include "sparse_matrix.h"
//---------------------------------------------------------------------------


t_proxy_arr::t_proxy_arr(t_matrix* aParent, size_t anIndex1)
: m_Parent(aParent),
m_nIndex1(anIndex1)
{
}
//---------------------------------------------------------------------------


t_final_proxy::t_final_proxy(t_matrix* aParent, size_t anIndex1, size_t anIndex2)
  :m_Parent(aParent),
  m_nIndex1(anIndex1),
  m_nIndex2(anIndex2)
{
}
//---------------------------------------------------------------------------


// Ñhar
t_final_proxy& t_final_proxy::operator = (const int& anSrc)
{
  m_Parent->set_value(m_nIndex1, m_nIndex2, anSrc);

  return *this;
}
//---------------------------------------------------------------------------


t_final_proxy::operator int() const
{
  return m_Parent->get_value(m_nIndex1, m_nIndex2);
}
//---------------------------------------------------------------------------