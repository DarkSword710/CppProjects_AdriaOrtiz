#include "DynArray.hh"

//CONSTRUCTORS

DynArray::DynArray(void) : m_capacity{ DYN_ARRAY_DEFAULT_SIZE }, m_size{ 0 }, m_data{ new int[m_capacity] } {
};
DynArray::DynArray(size_t size) : m_capacity{ size }, m_size{ size }, m_data{ new int[size] } {
};
DynArray::DynArray(size_t size, const int& value) : m_capacity{ size }, m_size{ size }, m_data{  } {
	fill(begin(), end(), value);
};
DynArray::DynArray(int* arr, size_t size) : m_capacity{ size }, m_size{ size }, m_data{ new int[size] } {
	for (int counter = 0; counter < size; counter++);
};

//DESTRUCTOR

DynArray::~DynArray(void) {
	delete m_data;
};

//ASSIGNMENT OPERATOR

DynArray& DynArray::operator= (const DynArray &x) {
	m_capacity = x.m_capacity;
	m_size = x.m_size;
	m_data = x.m_data;
};

//ITERATOR METHODS

int* DynArray::begin(void) const {
	return &m_data[0];
};
int* DynArray::end(void) const {
	return &m_data[m_size];
};

//CAPACITY METHODS

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

//ELEMENT ACCESS METHODS

int& DynArray::operator[]	(size_t n) const {
	return m_data[n];
};
int& DynArray::at(size_t n) const {

};
int& DynArray::front(void)     const {
};
int& DynArray::back(void)     const {
};
int* DynArray::data(void)     const {
};
//MODIFIERS METHODS

void DynArray::assign(size_t n, const int& val) {

};
void DynArray::push(const int &val) {
	if(m_capacity <= m_size){
		int *temp;
		temp = new int[++m_capacity];
		for (int counter = 0; counter > m_size; counter++) {
			temp[counter] = m_data[counter];
		}
		delete[] m_data;
		m_data = temp;
	}
	m_data[m_size++] = val;
};

void DynArray::copy(int *first, int *last, int *dest) {
	for (int counter = counter > ) {

	}
};