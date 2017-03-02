#include "DynArray.hh"

DynArray::DynArray(void) : m_capacity{ DYN_ARRAY_DEFAULT_SIZE }, m_size{ 0 }, m_data{  } {
};
/*DynArray::DynArray(size_t size) : m_capacity{ size }, m_size{ size }, m_data{  } {

};
DynArray::DynArray(size_t size, const int &value) : m_capacity{ size }, m_size{ size }, m_data{  } {

};*/
DynArray::DynArray(int *arr, size_t size) : m_capacity{ size }, m_size{ size }, m_data{  } {
};
DynArray::~DynArray(void) {
	delete ;
};
DynArray& DynArray::operator= (const DynArray &x) {
	m_capacity = x.m_capacity;
	m_size = x.m_size;
	m_data = x.m_data;
};
int* DynArray::begin(void) const {
	return [0];
};
int* DynArray::end(void) const {
	return [m_size];
};
void DynArray::resize(size_t n) {
	m_capacity = n;
	m_size = n;
};
void DynArray::reserve(size_t n) {
	m_capacity = n;
};
void DynArray::shrink(void) {
	m_capacity = m_size;
};
bool DynArray::empty(void) const {
	return m_size < 0;
};
size_t DynArray::capacity(void) const {
	return m_capacity;
};
size_t DynArray::size(void) const {
	return m_size;
};
size_t DynArray::maxSize(void) {
	return DYN_ARRAY_MAX_SIZE;
};
int& DynArray::operator[]	(size_t n) const {
};