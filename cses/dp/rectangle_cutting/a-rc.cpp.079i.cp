
IPA constant propagation start:
Determining dynamic type for call: std::_Vector_base<int, std::allocator<int> >::_M_create_storage (_1, _6);
  Starting walk at: std::_Vector_base<int, std::allocator<int> >::_M_create_storage (_1, _6);
  instance pointer: _1  Outer instance pointer: this_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: __builtin_memmove (_2, _16, _13);
  Starting walk at: __builtin_memmove (_2, _16, _13);
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:std::_Vector_base<int, std::allocator<int> >::_M_create_storage (_1, _6);
Determining dynamic type for call: __builtin_memmove (_2, _16, _13);
  Starting walk at: __builtin_memmove (_2, _16, _13);
  instance pointer: _16  Outer instance pointer: _16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:std::_Vector_base<int, std::allocator<int> >::_M_create_storage (_1, _6);
Determining dynamic type for call: std::vector<int>::vector (__cur_3, __x_10(D));
  Starting walk at: std::vector<int>::vector (__cur_3, __x_10(D));
  instance pointer: __cur_3  Outer instance pointer: __cur_3 offset: 0 (bits) vtbl reference: 
  Checking constructor call: std::vector<int>::vector (__cur_3, __x_10(D));
  Recording type: struct vector at offset 0
  Found multiple types (function entry reached) (multiple types encountered)
Determining dynamic type for call: std::vector<int>::vector (__cur_3, __x_10(D));
  Starting walk at: std::vector<int>::vector (__cur_3, __x_10(D));
  instance pointer: __x_10(D)  Outer instance pointer: __x_10(D) offset: 0 (bits) vtbl reference: 
  Checking constructor call: std::vector<int>::vector (__cur_3, __x_10(D));
  Function call may change dynamic type:std::vector<int>::vector (__cur_3, __x_10(D));
Determining dynamic type for call: std::_Vector_base<int, std::allocator<int> >::~_Vector_base (_16);
  Starting walk at: std::_Vector_base<int, std::allocator<int> >::~_Vector_base (_16);
  instance pointer: _16  Outer instance pointer: __first_9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:__cxa_begin_catch (_1);
  Checking constructor call: std::vector<int>::vector (__cur_3, __x_10(D));
  Function call may change dynamic type:std::vector<int>::vector (__cur_3, __x_10(D));
  Function call may change dynamic type:std::_Vector_base<int, std::allocator<int> >::~_Vector_base (_16);
Determining dynamic type for call: _10 = __gnu_cxx::new_allocator<std::vector<int> >::allocate (_9, __n_5(D), 0B);
  Starting walk at: _10 = __gnu_cxx::new_allocator<std::vector<int> >::allocate (_9, __n_5(D), 0B);
  instance pointer: _9  Outer instance pointer: this_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = __gnu_cxx::new_allocator<std::vector<int> >::allocate (_9, __n_5(D), 0B);
  Starting walk at: _10 = __gnu_cxx::new_allocator<std::vector<int> >::allocate (_9, __n_5(D), 0B);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = __gnu_cxx::new_allocator<int>::allocate (_9, __n_5(D), 0B);
  Starting walk at: _10 = __gnu_cxx::new_allocator<int>::allocate (_9, __n_5(D), 0B);
  instance pointer: _9  Outer instance pointer: this_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = __gnu_cxx::new_allocator<int>::allocate (_9, __n_5(D), 0B);
  Starting walk at: _10 = __gnu_cxx::new_allocator<int>::allocate (_9, __n_5(D), 0B);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = std::_ZSt10__fill_n_aIPimiET_S1_T0_RKT1_St26random_access_iterator_tag.part.0 (_1, __n_5(D), __value_6(D));
  Starting walk at: _4 = std::_ZSt10__fill_n_aIPimiET_S1_T0_RKT1_St26random_access_iterator_tag.part.0 (_1, __n_5(D), __value_6(D));
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = std::_ZSt10__fill_n_aIPimiET_S1_T0_RKT1_St26random_access_iterator_tag.part.0 (_1, __n_5(D), __value_6(D));
  Starting walk at: _4 = std::_ZSt10__fill_n_aIPimiET_S1_T0_RKT1_St26random_access_iterator_tag.part.0 (_1, __n_5(D), __value_6(D));
  instance pointer: __value_6(D)  Outer instance pointer: __value_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: std::_Vector_base<std::vector<int>, std::allocator<std::vector<int> > >::~_Vector_base (_3);
  Starting walk at: std::_Vector_base<std::vector<int>, std::allocator<std::vector<int> > >::~_Vector_base (_3);
  instance pointer: _3  Outer instance pointer: this_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:std::_Vector_base<int, std::allocator<int> >::~_Vector_base (_9);
Determining dynamic type for call: std::_Vector_base<int, std::allocator<int> >::~_Vector_base (_9);
  Starting walk at: std::_Vector_base<int, std::allocator<int> >::~_Vector_base (_9);
  instance pointer: _9  Outer instance pointer: __first_6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:std::_Vector_base<int, std::allocator<int> >::~_Vector_base (_9);
Determining dynamic type for call: std::_Vector_base<std::vector<int>, std::allocator<std::vector<int> > >::_M_create_storage (_1, __n_5(D));
  Starting walk at: std::_Vector_base<std::vector<int>, std::allocator<std::vector<int> > >::_M_create_storage (_1, __n_5(D));
  instance pointer: _1  Outer instance pointer: this_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = std::__uninitialized_fill_n<false>::__uninit_fill_n<std::vector<int>*, long unsigned int, std::vector<int> > (_9, __n_5(D), __value_7(D));
  Starting walk at: _10 = std::__uninitialized_fill_n<false>::__uninit_fill_n<std::vector<int>*, long unsigned int, std::vector<int> > (_9, __n_5(D), __value_7(D));
  instance pointer: _9  Outer instance pointer: _9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:std::_Vector_base<std::vector<int>, std::allocator<std::vector<int> > >::_M_create_storage (_1, __n_5(D));
Determining dynamic type for call: _10 = std::__uninitialized_fill_n<false>::__uninit_fill_n<std::vector<int>*, long unsigned int, std::vector<int> > (_9, __n_5(D), __value_7(D));
  Starting walk at: _10 = std::__uninitialized_fill_n<false>::__uninit_fill_n<std::vector<int>*, long unsigned int, std::vector<int> > (_9, __n_5(D), __value_7(D));
  instance pointer: __value_7(D)  Outer instance pointer: __value_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:std::_Vector_base<std::vector<int>, std::allocator<std::vector<int> > >::_M_create_storage (_1, __n_5(D));
Determining dynamic type for call: std::_Vector_base<std::vector<int>, std::allocator<std::vector<int> > >::~_Vector_base (_1);
  Starting walk at: std::_Vector_base<std::vector<int>, std::allocator<std::vector<int> > >::~_Vector_base (_1);
  instance pointer: _1  Outer instance pointer: this_3(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_10 = std::__uninitialized_fill_n<false>::__uninit_fill_n<std::vector<int>*, long unsigned int, std::vector<int> > (_9, __n_5(D), __value_7(D));
  Function call may change dynamic type:std::_Vector_base<std::vector<int>, std::allocator<std::vector<int> > >::_M_create_storage (_1, __n_5(D));
Determining dynamic type for call: std::_Vector_base<int, std::allocator<int> >::_M_create_storage (_1, __n_5(D));
  Starting walk at: std::_Vector_base<int, std::allocator<int> >::_M_create_storage (_1, __n_5(D));
  instance pointer: _1  Outer instance pointer: this_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: std::vector<int>::_M_fill_initialize (this_3(D), __n_5(D), __value_7(D));
  Starting walk at: std::vector<int>::_M_fill_initialize (this_3(D), __n_5(D), __value_7(D));
  instance pointer: this_3(D)  Outer instance pointer: this_3(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:std::_Vector_base<int, std::allocator<int> >::_M_create_storage (_1, __n_5(D));
Determining dynamic type for call: std::vector<int>::_M_fill_initialize (this_3(D), __n_5(D), __value_7(D));
  Starting walk at: std::vector<int>::_M_fill_initialize (this_3(D), __n_5(D), __value_7(D));
  instance pointer: __value_7(D)  Outer instance pointer: __value_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:std::_Vector_base<int, std::allocator<int> >::_M_create_storage (_1, __n_5(D));
Determining dynamic type for call: std::vector<int>::vector (&D.213808, _3, &D.213805, &D.213807);
  Starting walk at: std::vector<int>::vector (&D.213808, _3, &D.213805, &D.213807);
  instance pointer: &D.213808  Outer instance pointer: D.213808 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:std::basic_istream<char>::operator>> (_51, &b);
  Function call may change dynamic type:_51 = std::basic_istream<char>::operator>> (&cin, &a);
Determining dynamic type for call: std::vector<int>::vector (&D.213808, _3, &D.213805, &D.213807);
  Starting walk at: std::vector<int>::vector (&D.213808, _3, &D.213805, &D.213807);
  instance pointer: &D.213805  Outer instance pointer: D.213805 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:std::basic_istream<char>::operator>> (_51, &b);
  Function call may change dynamic type:_51 = std::basic_istream<char>::operator>> (&cin, &a);
Determining dynamic type for call: std::vector<int>::vector (&D.213808, _3, &D.213805, &D.213807);
  Starting walk at: std::vector<int>::vector (&D.213808, _3, &D.213805, &D.213807);
  instance pointer: &D.213807  Outer instance pointer: D.213807 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:std::basic_istream<char>::operator>> (_51, &b);
  Function call may change dynamic type:_51 = std::basic_istream<char>::operator>> (&cin, &a);
Determining dynamic type for call: std::vector<std::vector<int> >::vector (&dp, _6, &D.213808, &D.213864);
  Starting walk at: std::vector<std::vector<int> >::vector (&dp, _6, &D.213808, &D.213864);
  instance pointer: &dp  Outer instance pointer: dp offset: 0 (bits) vtbl reference: 
  Checking constructor call: std::vector<int>::vector (&D.213808, _3, &D.213805, &D.213807);
  Function call may change dynamic type:std::vector<int>::vector (&D.213808, _3, &D.213805, &D.213807);
  Function call may change dynamic type:std::basic_istream<char>::operator>> (_51, &b);
  Function call may change dynamic type:_51 = std::basic_istream<char>::operator>> (&cin, &a);
Determining dynamic type for call: std::vector<std::vector<int> >::vector (&dp, _6, &D.213808, &D.213864);
  Starting walk at: std::vector<std::vector<int> >::vector (&dp, _6, &D.213808, &D.213864);
  instance pointer: &D.213808  Outer instance pointer: D.213808 offset: 0 (bits) vtbl reference: 
  Checking constructor call: std::vector<int>::vector (&D.213808, _3, &D.213805, &D.213807);
  Recording type: struct vector at offset 0
  Determined dynamic type.
Determining dynamic type for call: std::vector<std::vector<int> >::vector (&dp, _6, &D.213808, &D.213864);
  Starting walk at: std::vector<std::vector<int> >::vector (&dp, _6, &D.213808, &D.213864);
  instance pointer: &D.213864  Outer instance pointer: D.213864 offset: 0 (bits) vtbl reference: 
  Checking constructor call: std::vector<int>::vector (&D.213808, _3, &D.213805, &D.213807);
  Function call may change dynamic type:std::vector<int>::vector (&D.213808, _3, &D.213805, &D.213807);
  Function call may change dynamic type:std::basic_istream<char>::operator>> (_51, &b);
  Function call may change dynamic type:_51 = std::basic_istream<char>::operator>> (&cin, &a);
Determining dynamic type for call: std::_Vector_base<int, std::allocator<int> >::~_Vector_base (&D.213808.D.182734);
  Starting walk at: std::_Vector_base<int, std::allocator<int> >::~_Vector_base (&D.213808.D.182734);
  instance pointer: &D.213808.D.182734  Outer instance pointer: D.213808 offset: 0 (bits) vtbl reference: 
  Checking constructor call: std::vector<std::vector<int> >::vector (&dp, _6, &D.213808, &D.213864);
  Function call may change dynamic type:std::vector<std::vector<int> >::vector (&dp, _6, &D.213808, &D.213864);
  Checking constructor call: std::vector<int>::vector (&D.213808, _3, &D.213805, &D.213807);
  Recording type: struct vector at offset 0
  Determined speculative dynamic type.
Determining dynamic type for call: std::vector<std::vector<int> >::~vector (&dp);
  Starting walk at: std::vector<std::vector<int> >::~vector (&dp);
  instance pointer: &dp  Outer instance pointer: dp offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:std::__ostream_insert<char, std::char_traits<char> > (_65, &__c, 1);
  Function call may change dynamic type:_65 = std::basic_ostream<char>::operator<< (&cout, _36);
  Function call may change dynamic type:std::_Vector_base<int, std::allocator<int> >::~_Vector_base (&D.213808.D.182734);
  Checking constructor call: std::vector<std::vector<int> >::vector (&dp, _6, &D.213808, &D.213864);
  Recording type: struct vector at offset 0
  Determined speculative dynamic type.
Determining dynamic type for call: std::vector<std::vector<int> >::~vector (&dp);
  Starting walk at: std::vector<std::vector<int> >::~vector (&dp);
  instance pointer: &dp  Outer instance pointer: dp offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_65 = std::basic_ostream<char>::operator<< (&cout, _36);
  Function call may change dynamic type:std::_Vector_base<int, std::allocator<int> >::~_Vector_base (&D.213808.D.182734);
  Checking constructor call: std::vector<std::vector<int> >::vector (&dp, _6, &D.213808, &D.213864);
  Recording type: struct vector at offset 0
  Function call may change dynamic type:std::__ostream_insert<char, std::char_traits<char> > (_65, &__c, 1);
  Determined speculative dynamic type.
Determining dynamic type for call: std::_Vector_base<int, std::allocator<int> >::~_Vector_base (&D.213808.D.182734);
  Starting walk at: std::_Vector_base<int, std::allocator<int> >::~_Vector_base (&D.213808.D.182734);
  instance pointer: &D.213808.D.182734  Outer instance pointer: D.213808 offset: 0 (bits) vtbl reference: 
  Checking constructor call: std::vector<std::vector<int> >::vector (&dp, _6, &D.213808, &D.213864);
  Function call may change dynamic type:std::vector<std::vector<int> >::vector (&dp, _6, &D.213808, &D.213864);
  Checking constructor call: std::vector<int>::vector (&D.213808, _3, &D.213805, &D.213807);
  Recording type: struct vector at offset 0
  Determined speculative dynamic type.

IPA structures before propagation:

Jump functions:
  Jump functions of caller  _OutputIterator std::__fill_n_a(_OutputIterator, _Size, const _Tp&, std::random_access_iterator_tag) [with _OutputIterator = int*; _Size = long unsigned int; _Tp = int]/5500:
  Jump functions of caller  std::ios_base::Init::~Init()/5481:
  Jump functions of caller  int __cxxabiv1::__cxa_atexit(void (*)(void*), void*, void*)/5480:
  Jump functions of caller  std::ios_base::Init::Init()/5479:
  Jump functions of caller  std::basic_ostream<_CharT, _Traits>& std::__ostream_insert(std::basic_ostream<_CharT, _Traits>&, const _CharT*, std::streamsize) [with _CharT = char; _Traits = std::char_traits<char>]/5478:
  Jump functions of caller  void* __builtin_memmove(void*, const void*, long unsigned int)/5477:
  Jump functions of caller  void __cxa_end_catch()/5476:
  Jump functions of caller  void __cxa_rethrow()/5475:
  Jump functions of caller  void* __cxa_begin_catch(void*)/5474:
  Jump functions of caller  void* __builtin_eh_pointer(int)/5473:
  Jump functions of caller  void operator delete(void*, std::size_t)/5472:
  Jump functions of caller  void* operator new(std::size_t)/5471:
  Jump functions of caller  void std::__throw_bad_alloc()/5470:
  Jump functions of caller  void std::__throw_bad_array_new_length()/5469:
  Jump functions of caller  long int __builtin_expect(long int, long int)/5468:
  Jump functions of caller  void std::__throw_length_error(const char*)/5467:
  Jump functions of caller  __gxx_personality_v0/5466:
  Jump functions of caller  std::basic_ostream<_CharT, _Traits>& std::basic_ostream<_CharT, _Traits>::operator<<(int) [with _CharT = char; _Traits = std::char_traits<char>]/5464:
  Jump functions of caller  std::basic_istream<_CharT, _Traits>& std::basic_istream<_CharT, _Traits>::operator>>(int&) [with _CharT = char; _Traits = std::char_traits<char>]/5462:
  Jump functions of caller  (static initializers for rc.cpp)/5461:
    callsite  (static initializers for rc.cpp)/5461 -> void __static_initialization_and_destruction_0(int, int)/5238 : 
       param 0: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 1: CONST: 65535
         value: 0xffff, mask: 0x0
         Unknown VR
  Jump functions of caller  void __static_initialization_and_destruction_0(int, int)/5238:
    callsite  void __static_initialization_and_destruction_0(int, int)/5238 -> int __cxxabiv1::__cxa_atexit(void (*)(void*), void*, void*)/5480 : 
       no arg info
    callsite  void __static_initialization_and_destruction_0(int, int)/5238 -> std::ios_base::Init::Init()/5479 : 
       no arg info
  Jump functions of caller  std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = int; _Alloc = std::allocator<int>]/4981:
  Jump functions of caller  std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = int; _Alloc = std::allocator<int>]/4980:
    callsite  std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = int; _Alloc = std::allocator<int>]/4980 -> void* __builtin_memmove(void*, const void*, long unsigned int)/5477 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffffffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffffffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffffffffffc
         Unknown VR
    callsite  std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = int; _Alloc = std::allocator<int>]/4980 -> void std::_Vector_base<_Tp, _Alloc>::_M_create_storage(std::size_t) [with _Tp = int; _Alloc = std::allocator<int>]/4588 : 
       param 0: ANCESTOR: 0, offset 0
         value: 0x0, mask: 0xffffffffffffffff
         VR  [1, -1]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffffffffffff
         VR  ~[2305843009213693952, -2305843009213693953]
  Jump functions of caller  _Tp* __gnu_cxx::new_allocator<_Tp>::allocate(__gnu_cxx::new_allocator<_Tp>::size_type, const void*) [with _Tp = std::vector<int>]/4913:
    callsite  _Tp* __gnu_cxx::new_allocator<_Tp>::allocate(__gnu_cxx::new_allocator<_Tp>::size_type, const void*) [with _Tp = std::vector<int>]/4913 -> void* operator new(std::size_t)/5471 : 
       no arg info
    callsite  _Tp* __gnu_cxx::new_allocator<_Tp>::allocate(__gnu_cxx::new_allocator<_Tp>::size_type, const void*) [with _Tp = std::vector<int>]/4913 -> void std::__throw_bad_alloc()/5470 : 
       no arg info
    callsite  _Tp* __gnu_cxx::new_allocator<_Tp>::allocate(__gnu_cxx::new_allocator<_Tp>::size_type, const void*) [with _Tp = std::vector<int>]/4913 -> void std::__throw_bad_array_new_length()/5469 : 
       no arg info
    callsite  _Tp* __gnu_cxx::new_allocator<_Tp>::allocate(__gnu_cxx::new_allocator<_Tp>::size_type, const void*) [with _Tp = std::vector<int>]/4913 -> long int __builtin_expect(long int, long int)/5468 : 
       no arg info
  Jump functions of caller  _Tp* __gnu_cxx::new_allocator<_Tp>::allocate(__gnu_cxx::new_allocator<_Tp>::size_type, const void*) [with _Tp = int]/4910:
    callsite  _Tp* __gnu_cxx::new_allocator<_Tp>::allocate(__gnu_cxx::new_allocator<_Tp>::size_type, const void*) [with _Tp = int]/4910 -> void* operator new(std::size_t)/5471 : 
       no arg info
    callsite  _Tp* __gnu_cxx::new_allocator<_Tp>::allocate(__gnu_cxx::new_allocator<_Tp>::size_type, const void*) [with _Tp = int]/4910 -> void std::__throw_bad_alloc()/5470 : 
       no arg info
    callsite  _Tp* __gnu_cxx::new_allocator<_Tp>::allocate(__gnu_cxx::new_allocator<_Tp>::size_type, const void*) [with _Tp = int]/4910 -> void std::__throw_bad_array_new_length()/5469 : 
       no arg info
    callsite  _Tp* __gnu_cxx::new_allocator<_Tp>::allocate(__gnu_cxx::new_allocator<_Tp>::size_type, const void*) [with _Tp = int]/4910 -> long int __builtin_expect(long int, long int)/5468 : 
       no arg info
  Jump functions of caller  static _ForwardIterator std::__uninitialized_fill_n<_TrivialValueType>::__uninit_fill_n(_ForwardIterator, _Size, const _Tp&) [with _ForwardIterator = std::vector<int>*; _Size = long unsigned int; _Tp = std::vector<int>; bool _TrivialValueType = false]/4823:
    callsite  static _ForwardIterator std::__uninitialized_fill_n<_TrivialValueType>::__uninit_fill_n(_ForwardIterator, _Size, const _Tp&) [with _ForwardIterator = std::vector<int>*; _Size = long unsigned int; _Tp = std::vector<int>; bool _TrivialValueType = false]/4823 -> void __cxa_end_catch()/5476 : 
       no arg info
    callsite  static _ForwardIterator std::__uninitialized_fill_n<_TrivialValueType>::__uninit_fill_n(_ForwardIterator, _Size, const _Tp&) [with _ForwardIterator = std::vector<int>*; _Size = long unsigned int; _Tp = std::vector<int>; bool _TrivialValueType = false]/4823 -> void __cxa_rethrow()/5475 : 
       no arg info
    callsite  static _ForwardIterator std::__uninitialized_fill_n<_TrivialValueType>::__uninit_fill_n(_ForwardIterator, _Size, const _Tp&) [with _ForwardIterator = std::vector<int>*; _Size = long unsigned int; _Tp = std::vector<int>; bool _TrivialValueType = false]/4823 -> std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = int; _Alloc = std::allocator<int>]/4318 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffffffffffff
         Unknown VR
    callsite  static _ForwardIterator std::__uninitialized_fill_n<_TrivialValueType>::__uninit_fill_n(_ForwardIterator, _Size, const _Tp&) [with _ForwardIterator = std::vector<int>*; _Size = long unsigned int; _Tp = std::vector<int>; bool _TrivialValueType = false]/4823 -> void* __cxa_begin_catch(void*)/5474 : 
       no arg info
    callsite  static _ForwardIterator std::__uninitialized_fill_n<_TrivialValueType>::__uninit_fill_n(_ForwardIterator, _Size, const _Tp&) [with _ForwardIterator = std::vector<int>*; _Size = long unsigned int; _Tp = std::vector<int>; bool _TrivialValueType = false]/4823 -> void* __builtin_eh_pointer(int)/5473 : 
       no arg info
    callsite  static _ForwardIterator std::__uninitialized_fill_n<_TrivialValueType>::__uninit_fill_n(_ForwardIterator, _Size, const _Tp&) [with _ForwardIterator = std::vector<int>*; _Size = long unsigned int; _Tp = std::vector<int>; bool _TrivialValueType = false]/4823 -> std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = int; _Alloc = std::allocator<int>]/4981 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffffffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffffffffffff
         Unknown VR
  Jump functions of caller  void std::_Vector_base<_Tp, _Alloc>::_M_create_storage(std::size_t) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/4600:
    callsite  void std::_Vector_base<_Tp, _Alloc>::_M_create_storage(std::size_t) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/4600 -> _Tp* __gnu_cxx::new_allocator<_Tp>::allocate(__gnu_cxx::new_allocator<_Tp>::size_type, const void*) [with _Tp = std::vector<int>]/4913 : 
       param 0: ANCESTOR: 0, offset 0, agg_preserved
         value: 0x0, mask: 0xffffffffffffffff
         VR  [1, -1]
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffffffffffff
         Unknown VR
       param 2: CONST: 0B
         value: 0x0, mask: 0xfffffffffffffff0
         Unknown VR
  Jump functions of caller  void std::_Vector_base<_Tp, _Alloc>::_M_create_storage(std::size_t) [with _Tp = int; _Alloc = std::allocator<int>]/4588:
    callsite  void std::_Vector_base<_Tp, _Alloc>::_M_create_storage(std::size_t) [with _Tp = int; _Alloc = std::allocator<int>]/4588 -> _Tp* __gnu_cxx::new_allocator<_Tp>::allocate(__gnu_cxx::new_allocator<_Tp>::size_type, const void*) [with _Tp = int]/4910 : 
       param 0: ANCESTOR: 0, offset 0, agg_preserved
         value: 0x0, mask: 0xffffffffffffffff
         VR  [1, -1]
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffffffffffff
         Unknown VR
       param 2: CONST: 0B
         value: 0x0, mask: 0xfffffffffffffff0
         Unknown VR
  Jump functions of caller  std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/4338:
  Jump functions of caller  std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/4337:
    callsite  std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/4337 -> void operator delete(void*, std::size_t)/5472 : 
       no arg info
  Jump functions of caller  void std::vector<_Tp, _Alloc>::_M_fill_initialize(std::vector<_Tp, _Alloc>::size_type, const value_type&) [with _Tp = int; _Alloc = std::allocator<int>]/4320:
    callsite  void std::vector<_Tp, _Alloc>::_M_fill_initialize(std::vector<_Tp, _Alloc>::size_type, const value_type&) [with _Tp = int; _Alloc = std::allocator<int>]/4320 -> _OutputIterator std::__fill_n_a(_OutputIterator, _Size, const _Tp&, std::random_access_iterator_tag) [with _OutputIterator = int*; _Size = long unsigned int; _Tp = int]/5500 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffffffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffffffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffffffffffff
         Unknown VR
  Jump functions of caller  std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = int; _Alloc = std::allocator<int>]/4319:
  Jump functions of caller  std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = int; _Alloc = std::allocator<int>]/4318:
    callsite  std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = int; _Alloc = std::allocator<int>]/4318 -> void operator delete(void*, std::size_t)/5472 : 
       no arg info
  Jump functions of caller  std::vector<_Tp, _Alloc>::~vector() [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/3927:
  Jump functions of caller  std::vector<_Tp, _Alloc>::~vector() [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/3926:
    callsite  std::vector<_Tp, _Alloc>::~vector() [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/3926 -> std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/4337 : 
       param 0: ANCESTOR: 0, offset 0
         value: 0x0, mask: 0xffffffffffffffff
         VR  [1, -1]
    callsite  std::vector<_Tp, _Alloc>::~vector() [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/3926 -> std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = int; _Alloc = std::allocator<int>]/4318 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffffffffffff
         Unknown VR
  Jump functions of caller  std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/3924:
  Jump functions of caller  std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/3923:
    callsite  std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/3923 -> std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/4337 : 
       param 0: ANCESTOR: 0, offset 0
         value: 0x0, mask: 0xffffffffffffffff
         VR  [1, -1]
    callsite  std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/3923 -> static _ForwardIterator std::__uninitialized_fill_n<_TrivialValueType>::__uninit_fill_n(_ForwardIterator, _Size, const _Tp&) [with _ForwardIterator = std::vector<int>*; _Size = long unsigned int; _Tp = std::vector<int>; bool _TrivialValueType = false]/4823 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffffffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffffffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffffffffffff
         Unknown VR
    callsite  std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/3923 -> void std::_Vector_base<_Tp, _Alloc>::_M_create_storage(std::size_t) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/4600 : 
       param 0: ANCESTOR: 0, offset 0
         value: 0x0, mask: 0xffffffffffffffff
         VR  [1, -1]
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffffffffffff
         Unknown VR
    callsite  std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/3923 -> void std::__throw_length_error(const char*)/5467 : 
       no arg info
  Jump functions of caller  std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = int; _Alloc = std::allocator<int>]/3912:
  Jump functions of caller  std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = int; _Alloc = std::allocator<int>]/3911:
    callsite  std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = int; _Alloc = std::allocator<int>]/3911 -> void std::vector<_Tp, _Alloc>::_M_fill_initialize(std::vector<_Tp, _Alloc>::size_type, const value_type&) [with _Tp = int; _Alloc = std::allocator<int>]/4320 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffffffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffffffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffffffffffff
         Unknown VR
    callsite  std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = int; _Alloc = std::allocator<int>]/3911 -> void std::_Vector_base<_Tp, _Alloc>::_M_create_storage(std::size_t) [with _Tp = int; _Alloc = std::allocator<int>]/4588 : 
       param 0: ANCESTOR: 0, offset 0
         value: 0x0, mask: 0xffffffffffffffff
         VR  [1, -1]
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffffffffffff
         Unknown VR
    callsite  std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = int; _Alloc = std::allocator<int>]/3911 -> void std::__throw_length_error(const char*)/5467 : 
       no arg info
  Jump functions of caller  int main()/3228:
    callsite  int main()/3228 -> std::vector<_Tp, _Alloc>::~vector() [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/3927 : 
       param 0: UNKNOWN
         Context:     Speculative outer type:struct vector at offset 0
         value: 0x0, mask: 0xfffffffffffffff8
         VR  [1, -1]
    callsite  int main()/3228 -> std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = int; _Alloc = std::allocator<int>]/4318 : 
       param 0: UNKNOWN
         Context:     Speculative outer type:struct vector at offset 0
         value: 0x0, mask: 0xfffffffffffffff8
         VR  [1, -1]
    callsite  int main()/3228 -> std::vector<_Tp, _Alloc>::~vector() [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/3927 : 
       param 0: UNKNOWN
         Context:     Speculative outer type:struct vector at offset 0
         value: 0x0, mask: 0xfffffffffffffff8
         VR  [1, -1]
    callsite  int main()/3228 -> std::basic_ostream<_CharT, _Traits>& std::__ostream_insert(std::basic_ostream<_CharT, _Traits>&, const _CharT*, std::streamsize) [with _CharT = char; _Traits = std::char_traits<char>]/5478 : 
       no arg info
    callsite  int main()/3228 -> std::basic_ostream<_CharT, _Traits>& std::basic_ostream<_CharT, _Traits>::operator<<(int) [with _CharT = char; _Traits = std::char_traits<char>]/5464 : 
       no arg info
    callsite  int main()/3228 -> std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = int; _Alloc = std::allocator<int>]/4318 : 
       param 0: UNKNOWN
         Context:     Speculative outer type:struct vector at offset 0
         value: 0x0, mask: 0xfffffffffffffff8
         VR  [1, -1]
    callsite  int main()/3228 -> std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/3924 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffffffffff8
         VR  [1, -1]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffffffffffff
         VR  ~[2147483648, -2147483648]
       param 2: UNKNOWN
         Context:     Outer type (dynamic):struct vector offset 0
         value: 0x0, mask: 0xfffffffffffffff8
         VR  [1, -1]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffffffffffff
         VR  [1, -1]
    callsite  int main()/3228 -> std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = int; _Alloc = std::allocator<int>]/3912 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffffffffff8
         VR  [1, -1]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffffffffffff
         VR  ~[2147483648, -2147483648]
       param 2: UNKNOWN
         Aggregate passed by reference:
           offset: 0, type: const value_type, CONST: 1000000000
         value: 0x0, mask: 0xfffffffffffffffc
         VR  [1, -1]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffffffffffff
         VR  [1, -1]
    callsite  int main()/3228 -> std::basic_istream<_CharT, _Traits>& std::basic_istream<_CharT, _Traits>::operator>>(int&) [with _CharT = char; _Traits = std::char_traits<char>]/5462 : 
       no arg info
    callsite  int main()/3228 -> std::basic_istream<_CharT, _Traits>& std::basic_istream<_CharT, _Traits>::operator>>(int&) [with _CharT = char; _Traits = std::char_traits<char>]/5462 : 
       no arg info

 Propagating constants:

Not considering std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = int; _Alloc = std::allocator<int>]/4980 for cloning; -fipa-cp-clone disabled.
Not considering _Tp* __gnu_cxx::new_allocator<_Tp>::allocate(__gnu_cxx::new_allocator<_Tp>::size_type, const void*) [with _Tp = std::vector<int>]/4913 for cloning; -fipa-cp-clone disabled.
Not considering _Tp* __gnu_cxx::new_allocator<_Tp>::allocate(__gnu_cxx::new_allocator<_Tp>::size_type, const void*) [with _Tp = int]/4910 for cloning; -fipa-cp-clone disabled.
Not considering static _ForwardIterator std::__uninitialized_fill_n<_TrivialValueType>::__uninit_fill_n(_ForwardIterator, _Size, const _Tp&) [with _ForwardIterator = std::vector<int>*; _Size = long unsigned int; _Tp = std::vector<int>; bool _TrivialValueType = false]/4823 for cloning; -fipa-cp-clone disabled.
Not considering void std::_Vector_base<_Tp, _Alloc>::_M_create_storage(std::size_t) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/4600 for cloning; -fipa-cp-clone disabled.
Not considering void std::_Vector_base<_Tp, _Alloc>::_M_create_storage(std::size_t) [with _Tp = int; _Alloc = std::allocator<int>]/4588 for cloning; -fipa-cp-clone disabled.
Not considering std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/4337 for cloning; -fipa-cp-clone disabled.
Not considering void std::vector<_Tp, _Alloc>::_M_fill_initialize(std::vector<_Tp, _Alloc>::size_type, const value_type&) [with _Tp = int; _Alloc = std::allocator<int>]/4320 for cloning; -fipa-cp-clone disabled.
Not considering std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = int; _Alloc = std::allocator<int>]/4318 for cloning; -fipa-cp-clone disabled.
Not considering std::vector<_Tp, _Alloc>::~vector() [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/3926 for cloning; -fipa-cp-clone disabled.
Not considering std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/3923 for cloning; -fipa-cp-clone disabled.
Not considering std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = int; _Alloc = std::allocator<int>]/3911 for cloning; -fipa-cp-clone disabled.

overall_size: 363
 - context independent values, size: 7, time_benefit: 4.680000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 16, time_benefit: 1.000000
 - context independent values, size: 23, time_benefit: 1.000000
 - context independent values, size: 11, time_benefit: 2.000000
 - context independent values, size: 11, time_benefit: 2.000000

IPA lattices after all propagation:

Lattices:
  Node: _OutputIterator std::__fill_n_a(_OutputIterator, _Size, const _Tp&, std::random_access_iterator_tag) [with _OutputIterator = int*; _Size = long unsigned int; _Tp = int]/5500:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
  Node: (static initializers for rc.cpp)/5461:
  Node: void __static_initialization_and_destruction_0(int, int)/5238:
    param [0]: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x0
         int [1, 1]
        AGGS VARIABLE
    param [1]: 65535 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0xffff, mask = 0x0
         int [65535, 65535]
        AGGS VARIABLE
  Node: std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = int; _Alloc = std::allocator<int>]/4980:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: _Tp* __gnu_cxx::new_allocator<_Tp>::allocate(__gnu_cxx::new_allocator<_Tp>::size_type, const void*) [with _Tp = std::vector<int>]/4913:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: _Tp* __gnu_cxx::new_allocator<_Tp>::allocate(__gnu_cxx::new_allocator<_Tp>::size_type, const void*) [with _Tp = int]/4910:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: static _ForwardIterator std::__uninitialized_fill_n<_TrivialValueType>::__uninit_fill_n(_ForwardIterator, _Size, const _Tp&) [with _ForwardIterator = std::vector<int>*; _Size = long unsigned int; _Tp = std::vector<int>; bool _TrivialValueType = false]/4823:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: void std::_Vector_base<_Tp, _Alloc>::_M_create_storage(std::size_t) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/4600:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: void std::_Vector_base<_Tp, _Alloc>::_M_create_storage(std::size_t) [with _Tp = int; _Alloc = std::allocator<int>]/4588:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/4337:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: void std::vector<_Tp, _Alloc>::_M_fill_initialize(std::vector<_Tp, _Alloc>::size_type, const value_type&) [with _Tp = int; _Alloc = std::allocator<int>]/4320:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = int; _Alloc = std::allocator<int>]/4318:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: std::vector<_Tp, _Alloc>::~vector() [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/3926:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/3923:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = int; _Alloc = std::allocator<int>]/3911:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: int main()/3228:

IPA decision stage:

 - Creating a specialized node of void __static_initialization_and_destruction_0(int, int)/5238 for all known contexts.
    replacing param #0 __initialize_p with const 1
    replacing param #1 __priority with const 65535
Propagated bits info for function __static_initialization_and_destruction_0.constprop/5531:
 param 0: value = 0x1, mask = 0x0
 param 1: value = 0xffff, mask = 0x0
Propagated bits info for function void __static_initialization_and_destruction_0(int, int)/5238:
 param 0: value = 0x1, mask = 0x0
 param 1: value = 0xffff, mask = 0x0

IPA constant propagation end

Reclaiming functions: void __static_initialization_and_destruction_0(int, int)/5238
Reclaiming variables:
Clearing address taken flags:
Node __static_initialization_and_destruction_0.constprop/5531 promoted to only called at startup.
Symbol table:

_Z41__static_initialization_and_destruction_0ii.constprop.0/5531 (__static_initialization_and_destruction_0.constprop) @0x7f114803d990
  Type: function definition analyzed
  Visibility: artificial
  References: _ZStL8__ioinit/1878 (addr) _ZNSt8ios_base4InitD1Ev/5481 (addr) _ZStL8__ioinit/1878 (addr) __dso_handle/5482 (addr) 
  Referring: 
  Clone of _Z41__static_initialization_and_destruction_0ii/5238
  Availability: local
  Function flags: count:1073741823 (estimated locally) local only_called_at_startup executed_once
  Called by: _GLOBAL__sub_I_main/5461 (1073741824 (estimated locally),1.00 per call) 
  Calls: _ZNSt8ios_base4InitC1Ev/5479 (73890618 (estimated locally),0.07 per call) (can throw external) __cxa_atexit/5480 (73890618 (estimated locally),0.07 per call) 
_ZSt10__fill_n_aIPimiET_S1_T0_RKT1_St26random_access_iterator_tag.part.0/5500 (_OutputIterator std::__fill_n_a(_OutputIterator, _Size, const _Tp&, std::random_access_iterator_tag) [with _OutputIterator = int*; _Size = long unsigned int; _Tp = int]) @0x7f114a088660
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local split_part
  Called by: _ZNSt6vectorIiSaIiEE18_M_fill_initializeEmRKi/4320 (708669601 (estimated locally),0.66 per call) 
  Calls: 
__dso_handle/5482 (void* __dso_handle) @0x7f113fab2600
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public visibility_specified visibility:hidden artificial
  References: 
  Referring: _Z41__static_initialization_and_destruction_0ii.constprop.0/5531 (addr) 
  Availability: not_available
  Varpool flags:
_ZNSt8ios_base4InitD1Ev/5481 (std::ios_base::Init::~Init()) @0x7f113fabe000
  Type: function
  Visibility: external public visibility_specified
  Address is taken.
  References: 
  Referring: _Z41__static_initialization_and_destruction_0ii.constprop.0/5531 (addr) 
  Availability: not_available
  Function flags:
  Called by: 
  Calls: 
__cxa_atexit/5480 (int __cxxabiv1::__cxa_atexit(void (*)(void*), void*, void*)) @0x7f113fa40ee0
  Type: function
  Visibility: external public visibility_specified artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags:
  Called by: _Z41__static_initialization_and_destruction_0ii.constprop.0/5531 (73890618 (estimated locally),0.07 per call) 
  Calls: 
_ZNSt8ios_base4InitC1Ev/5479 (std::ios_base::Init::Init()) @0x7f113fa40dd0
  Type: function
  Visibility: external public visibility_specified
  References: 
  Referring: 
  Availability: not_available
  Function flags:
  Called by: _Z41__static_initialization_and_destruction_0ii.constprop.0/5531 (73890618 (estimated locally),0.07 per call) (can throw external) 
  Calls: 
_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l/5478 (std::basic_ostream<_CharT, _Traits>& std::__ostream_insert(std::basic_ostream<_CharT, _Traits>&, const _CharT*, std::streamsize) [with _CharT = char; _Traits = std::char_traits<char>]) @0x7f113fa40cc0
  Type: function
  Visibility: external public visibility_specified
  References: 
  Referring: 
  Availability: not_available
  Function flags:
  Called by: main/3228 (3042075 (estimated locally),1.00 per call) 
  Calls: 
memmove/5477 (void* __builtin_memmove(void*, const void*, long unsigned int)) @0x7f113fa40bb0
  Type: function
  Visibility: external public visibility_specified artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags:
  Called by: _ZNSt6vectorIiSaIiEEC2ERKS1_/4980 (574129753 (estimated locally),0.53 per call) 
  Calls: 
__cxa_end_catch/5476 (void __cxa_end_catch()) @0x7f113fa40aa0
  Type: function
  Visibility: external public visibility_specified artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags:
  Called by: _ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorIiSaIiEEmS4_EET_S6_T0_RKT1_/4823 (0 (precise),0.00 per call) 
  Calls: 
__cxa_rethrow/5475 (void __cxa_rethrow()) @0x7f113fa40990
  Type: function
  Visibility: external public visibility_specified artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags:
  Called by: _ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorIiSaIiEEmS4_EET_S6_T0_RKT1_/4823 (0 (precise),0.00 per call) 
  Calls: 
__cxa_begin_catch/5474 (void* __cxa_begin_catch(void*)) @0x7f113fa40880
  Type: function
  Visibility: external public visibility_specified artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags:
  Called by: _ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorIiSaIiEEmS4_EET_S6_T0_RKT1_/4823 (0 (precise),0.00 per call) 
  Calls: 
__builtin_eh_pointer/5473 (void* __builtin_eh_pointer(int)) @0x7f113fa40770
  Type: function
  Visibility: external public visibility_specified artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags:
  Called by: _ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorIiSaIiEEmS4_EET_S6_T0_RKT1_/4823 (0 (precise),0.00 per call) 
  Calls: 
_ZdlPvm/5472 (void operator delete(void*, std::size_t)) @0x7f113fa40660
  Type: function
  Visibility: external public visibility_specified
  References: 
  Referring: 
  Availability: not_available
  Function flags: replaceable_operator_delete
  Called by: _ZNSt12_Vector_baseISt6vectorIiSaIiEESaIS2_EED2Ev/4337 (574129753 (estimated locally),0.53 per call) _ZNSt12_Vector_baseIiSaIiEED2Ev/4318 (574129753 (estimated locally),0.53 per call) 
  Calls: 
_Znwm/5471 (void* operator new(std::size_t)) @0x7f113fa40550
  Type: function
  Visibility: external public visibility_specified
  References: 
  Referring: 
  Availability: not_available
  Function flags: decl_is_malloc replaceable_operator_new
  Called by: _ZN9__gnu_cxx13new_allocatorISt6vectorIiSaIiEEE8allocateEmPKv/4913 (966367641 (estimated locally),0.90 per call) (can throw external) _ZN9__gnu_cxx13new_allocatorIiE8allocateEmPKv/4910 (966367641 (estimated locally),0.90 per call) (can throw external) 
  Calls: 
_ZSt17__throw_bad_allocv/5470 (void std::__throw_bad_alloc()) @0x7f113fa40440
  Type: function
  Visibility: external public visibility_specified
  References: 
  Referring: 
  Availability: not_available
  Function flags:
  Called by: _ZN9__gnu_cxx13new_allocatorISt6vectorIiSaIiEEE8allocateEmPKv/4913 (53687092 (estimated locally),0.05 per call) (can throw external) _ZN9__gnu_cxx13new_allocatorIiE8allocateEmPKv/4910 (53687092 (estimated locally),0.05 per call) (can throw external) 
  Calls: 
_ZSt28__throw_bad_array_new_lengthv/5469 (void std::__throw_bad_array_new_length()) @0x7f113fa40330
  Type: function
  Visibility: external public visibility_specified
  References: 
  Referring: 
  Availability: not_available
  Function flags:
  Called by: _ZN9__gnu_cxx13new_allocatorISt6vectorIiSaIiEEE8allocateEmPKv/4913 (53687092 (estimated locally),0.05 per call) (can throw external) _ZN9__gnu_cxx13new_allocatorIiE8allocateEmPKv/4910 (53687092 (estimated locally),0.05 per call) (can throw external) 
  Calls: 
__builtin_expect/5468 (long int __builtin_expect(long int, long int)) @0x7f113fa40220
  Type: function
  Visibility: external public visibility_specified artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags:
  Called by: _ZN9__gnu_cxx13new_allocatorISt6vectorIiSaIiEEE8allocateEmPKv/4913 (1073741824 (estimated locally),1.00 per call) _ZN9__gnu_cxx13new_allocatorIiE8allocateEmPKv/4910 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
_ZSt20__throw_length_errorPKc/5467 (void std::__throw_length_error(const char*)) @0x7f113fa40110
  Type: function
  Visibility: external public visibility_specified
  References: 
  Referring: 
  Availability: not_available
  Function flags:
  Called by: _ZNSt6vectorIS_IiSaIiEESaIS1_EEC2EmRKS1_RKS2_/3923 (429496 (estimated locally),0.00 per call) (can throw external) _ZNSt6vectorIiSaIiEEC2EmRKiRKS0_/3911 (429496 (estimated locally),0.00 per call) (can throw external) 
  Calls: 
__gxx_personality_v0/5466 (__gxx_personality_v0) @0x7f113fa40000
  Type: function
  Visibility: external public artificial
  Address is taken.
  References: 
  Referring: _ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorIiSaIiEEmS4_EET_S6_T0_RKT1_/4823 (addr) 
  Availability: not_available
  Function flags:
  Called by: 
  Calls: 
_ZSt4cout/5465 (std::ostream std::cout) @0x7f113f9fea80
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public visibility_specified
  References: 
  Referring: main/3228 (addr) 
  Availability: not_available
  Varpool flags:
_ZNSolsEi/5464 (std::basic_ostream<_CharT, _Traits>& std::basic_ostream<_CharT, _Traits>::operator<<(int) [with _CharT = char; _Traits = std::char_traits<char>]) @0x7f113fdbaee0
  Type: function
  Visibility: external public visibility_specified
  References: 
  Referring: 
  Availability: not_available
  Function flags:
  Called by: main/3228 (3042075 (estimated locally),1.00 per call) 
  Calls: 
_ZSt3cin/5463 (std::istream std::cin) @0x7f113f9fea00
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public visibility_specified
  References: 
  Referring: main/3228 (addr) 
  Availability: not_available
  Varpool flags:
_ZNSirsERi/5462 (std::basic_istream<_CharT, _Traits>& std::basic_istream<_CharT, _Traits>::operator>>(int&) [with _CharT = char; _Traits = std::char_traits<char>]) @0x7f113fdbadd0
  Type: function
  Visibility: external public visibility_specified
  References: 
  Referring: 
  Availability: not_available
  Function flags:
  Called by: main/3228 (3042075 (estimated locally),1.00 per call) (can throw external) main/3228 (3042075 (estimated locally),1.00 per call) (can throw external) 
  Calls: 
_GLOBAL__sub_I_main/5461 ((static initializers for rc.cpp)) @0x7f113fdba000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial constructor
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body only_called_at_startup static_constructor (priority:65535) executed_once
  Called by: 
  Calls: _Z41__static_initialization_and_destruction_0ii.constprop.0/5531 (1073741824 (estimated locally),1.00 per call) 
_Z41__static_initialization_and_destruction_0ii/5238 (void __static_initialization_and_destruction_0(int, int)) @0x7f113fd55770
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741823 (estimated locally) body only_called_at_startup executed_once
  Called by: 
  Calls: 
_ZNSt6vectorIiSaIiEEC1ERKS1_/4981 (std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = int; _Alloc = std::allocator<int>]) @0x7f113fc99550
  Type: function definition analyzed alias cpp_implicit_alias
  Visibility: externally_visible public weak comdat comdat_group:_ZNSt6vectorIiSaIiEEC5ERKS1_ one_only visibility_specified
  Same comdat group as: _ZNSt6vectorIiSaIiEEC2ERKS1_/4980
  References: _ZNSt6vectorIiSaIiEEC2ERKS1_/4980 (alias) 
  Referring: 
  Availability: available
  Function flags:
  Called by: _ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorIiSaIiEEmS4_EET_S6_T0_RKT1_/4823 (955630225 (estimated locally),8.09 per call) 
  Calls: 
_ZNSt6vectorIiSaIiEEC2ERKS1_/4980 (std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = int; _Alloc = std::allocator<int>]) @0x7f113fc99440
  Type: function definition analyzed
  Visibility: externally_visible public weak comdat comdat_group:_ZNSt6vectorIiSaIiEEC5ERKS1_ one_only visibility_specified
  Same comdat group as: _ZNSt6vectorIiSaIiEEC1ERKS1_/4981
  References: 
  Referring: _ZNSt6vectorIiSaIiEEC1ERKS1_/4981 (alias) 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body
  Called by: 
  Calls: memmove/5477 (574129753 (estimated locally),0.53 per call) _ZNSt12_Vector_baseIiSaIiEE17_M_create_storageEm/4588 (1073741824 (estimated locally),1.00 per call) (can throw external) 
_ZN9__gnu_cxx13new_allocatorISt6vectorIiSaIiEEE8allocateEmPKv/4913 (_Tp* __gnu_cxx::new_allocator<_Tp>::allocate(__gnu_cxx::new_allocator<_Tp>::size_type, const void*) [with _Tp = std::vector<int>]) @0x7f113fc56bb0
  Type: function definition analyzed
  Visibility: externally_visible public weak comdat comdat_group:_ZN9__gnu_cxx13new_allocatorISt6vectorIiSaIiEEE8allocateEmPKv one_only visibility_specified
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body decl_is_malloc
  Called by: _ZNSt12_Vector_baseISt6vectorIiSaIiEESaIS2_EE17_M_create_storageEm/4600 (587014657 (estimated locally),0.55 per call) (can throw external) 
  Calls: _Znwm/5471 (966367641 (estimated locally),0.90 per call) (can throw external) _ZSt17__throw_bad_allocv/5470 (53687092 (estimated locally),0.05 per call) (can throw external) _ZSt28__throw_bad_array_new_lengthv/5469 (53687092 (estimated locally),0.05 per call) (can throw external) __builtin_expect/5468 (1073741824 (estimated locally),1.00 per call) 
_ZN9__gnu_cxx13new_allocatorIiE8allocateEmPKv/4910 (_Tp* __gnu_cxx::new_allocator<_Tp>::allocate(__gnu_cxx::new_allocator<_Tp>::size_type, const void*) [with _Tp = int]) @0x7f113fc56880
  Type: function definition analyzed
  Visibility: externally_visible public weak comdat comdat_group:_ZN9__gnu_cxx13new_allocatorIiE8allocateEmPKv one_only visibility_specified
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body decl_is_malloc
  Called by: _ZNSt12_Vector_baseIiSaIiEE17_M_create_storageEm/4588 (587014657 (estimated locally),0.55 per call) (can throw external) 
  Calls: _Znwm/5471 (966367641 (estimated locally),0.90 per call) (can throw external) _ZSt17__throw_bad_allocv/5470 (53687092 (estimated locally),0.05 per call) (can throw external) _ZSt28__throw_bad_array_new_lengthv/5469 (53687092 (estimated locally),0.05 per call) (can throw external) __builtin_expect/5468 (1073741824 (estimated locally),1.00 per call) 
_ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorIiSaIiEEmS4_EET_S6_T0_RKT1_/4823 (static _ForwardIterator std::__uninitialized_fill_n<_TrivialValueType>::__uninit_fill_n(_ForwardIterator, _Size, const _Tp&) [with _ForwardIterator = std::vector<int>*; _Size = long unsigned int; _Tp = std::vector<int>; bool _TrivialValueType = false]) @0x7f113ffaedd0
  Type: function definition analyzed
  Visibility: externally_visible public weak comdat comdat_group:_ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorIiSaIiEEmS4_EET_S6_T0_RKT1_ one_only visibility_specified
  References: __gxx_personality_v0/5466 (addr) 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body
  Called by: _ZNSt6vectorIS_IiSaIiEESaIS1_EEC2EmRKS1_RKS2_/3923 (1073312329 (estimated locally),1.00 per call) 
  Calls: __cxa_end_catch/5476 (0 (precise),0.00 per call) __cxa_rethrow/5475 (0 (precise),0.00 per call) _ZNSt12_Vector_baseIiSaIiEED2Ev/4318 (0 (precise),0.00 per call) __cxa_begin_catch/5474 (0 (precise),0.00 per call) __builtin_eh_pointer/5473 (0 (precise),0.00 per call) _ZNSt6vectorIiSaIiEEC1ERKS1_/4981 (955630225 (estimated locally),8.09 per call) 
_ZNSt12_Vector_baseISt6vectorIiSaIiEESaIS2_EE17_M_create_storageEm/4600 (void std::_Vector_base<_Tp, _Alloc>::_M_create_storage(std::size_t) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]) @0x7f11401a2220
  Type: function definition analyzed
  Visibility: externally_visible public weak comdat comdat_group:_ZNSt12_Vector_baseISt6vectorIiSaIiEESaIS2_EE17_M_create_storageEm one_only visibility_specified
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body
  Called by: _ZNSt6vectorIS_IiSaIiEESaIS1_EEC2EmRKS1_RKS2_/3923 (1073312329 (estimated locally),1.00 per call) (can throw external) 
  Calls: _ZN9__gnu_cxx13new_allocatorISt6vectorIiSaIiEEE8allocateEmPKv/4913 (587014657 (estimated locally),0.55 per call) (can throw external) 
_ZNSt12_Vector_baseIiSaIiEE17_M_create_storageEm/4588 (void std::_Vector_base<_Tp, _Alloc>::_M_create_storage(std::size_t) [with _Tp = int; _Alloc = std::allocator<int>]) @0x7f114017a550
  Type: function definition analyzed
  Visibility: externally_visible public weak comdat comdat_group:_ZNSt12_Vector_baseIiSaIiEE17_M_create_storageEm one_only visibility_specified
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body
  Called by: _ZNSt6vectorIiSaIiEEC2ERKS1_/4980 (1073741824 (estimated locally),1.00 per call) (can throw external) _ZNSt6vectorIiSaIiEEC2EmRKiRKS0_/3911 (1073312329 (estimated locally),1.00 per call) (can throw external) 
  Calls: _ZN9__gnu_cxx13new_allocatorIiE8allocateEmPKv/4910 (587014657 (estimated locally),0.55 per call) (can throw external) 
_ZNSt12_Vector_baseISt6vectorIiSaIiEESaIS2_EED1Ev/4338 (std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]) @0x7f11403e9cc0
  Type: function definition analyzed alias cpp_implicit_alias
  Visibility: externally_visible public weak comdat comdat_group:_ZNSt12_Vector_baseISt6vectorIiSaIiEESaIS2_EED5Ev one_only visibility_specified
  Same comdat group as: _ZNSt12_Vector_baseISt6vectorIiSaIiEESaIS2_EED2Ev/4337
  References: _ZNSt12_Vector_baseISt6vectorIiSaIiEESaIS2_EED2Ev/4337 (alias) 
  Referring: 
  Availability: available
  Function flags:
  Called by: 
  Calls: 
_ZNSt12_Vector_baseISt6vectorIiSaIiEESaIS2_EED2Ev/4337 (std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]) @0x7f11403e9bb0
  Type: function definition analyzed
  Visibility: externally_visible public weak comdat comdat_group:_ZNSt12_Vector_baseISt6vectorIiSaIiEESaIS2_EED5Ev one_only visibility_specified
  Same comdat group as: _ZNSt12_Vector_baseISt6vectorIiSaIiEESaIS2_EED1Ev/4338
  References: 
  Referring: _ZNSt12_Vector_baseISt6vectorIiSaIiEESaIS2_EED1Ev/4338 (alias) 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body
  Called by: _ZNSt6vectorIS_IiSaIiEESaIS1_EEC2EmRKS1_RKS2_/3923 (0 (precise),0.00 per call) _ZNSt6vectorIS_IiSaIiEESaIS1_EED2Ev/3926 (118111600 (estimated locally),1.00 per call) 
  Calls: _ZdlPvm/5472 (574129753 (estimated locally),0.53 per call) 
_ZNSt6vectorIiSaIiEE18_M_fill_initializeEmRKi/4320 (void std::vector<_Tp, _Alloc>::_M_fill_initialize(std::vector<_Tp, _Alloc>::size_type, const value_type&) [with _Tp = int; _Alloc = std::allocator<int>]) @0x7f11403df990
  Type: function definition analyzed
  Visibility: externally_visible public weak comdat comdat_group:_ZNSt6vectorIiSaIiEE18_M_fill_initializeEmRKi one_only visibility_specified
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body
  Called by: _ZNSt6vectorIiSaIiEEC2EmRKiRKS0_/3911 (1073312329 (estimated locally),1.00 per call) 
  Calls: _ZSt10__fill_n_aIPimiET_S1_T0_RKT1_St26random_access_iterator_tag.part.0/5500 (708669601 (estimated locally),0.66 per call) 
_ZNSt12_Vector_baseIiSaIiEED1Ev/4319 (std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = int; _Alloc = std::allocator<int>]) @0x7f11403df880
  Type: function definition analyzed alias cpp_implicit_alias
  Visibility: externally_visible public weak comdat comdat_group:_ZNSt12_Vector_baseIiSaIiEED5Ev one_only visibility_specified
  Same comdat group as: _ZNSt12_Vector_baseIiSaIiEED2Ev/4318
  References: _ZNSt12_Vector_baseIiSaIiEED2Ev/4318 (alias) 
  Referring: 
  Availability: available
  Function flags:
  Called by: 
  Calls: 
_ZNSt12_Vector_baseIiSaIiEED2Ev/4318 (std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = int; _Alloc = std::allocator<int>]) @0x7f11403df770
  Type: function definition analyzed
  Visibility: externally_visible public weak comdat comdat_group:_ZNSt12_Vector_baseIiSaIiEED5Ev one_only visibility_specified
  Same comdat group as: _ZNSt12_Vector_baseIiSaIiEED1Ev/4319
  References: 
  Referring: _ZNSt12_Vector_baseIiSaIiEED1Ev/4319 (alias) 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body
  Called by: main/3228 (0 (precise),0.00 per call) main/3228 (3042075 (estimated locally),1.00 per call) _ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorIiSaIiEEmS4_EET_S6_T0_RKT1_/4823 (0 (precise),0.00 per call) _ZNSt6vectorIS_IiSaIiEESaIS1_EED2Ev/3926 (955630225 (estimated locally),8.09 per call) 
  Calls: _ZdlPvm/5472 (574129753 (estimated locally),0.53 per call) 
_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev/3927 (std::vector<_Tp, _Alloc>::~vector() [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]) @0x7f11404fb550
  Type: function definition analyzed alias cpp_implicit_alias
  Visibility: externally_visible public weak comdat comdat_group:_ZNSt6vectorIS_IiSaIiEESaIS1_EED5Ev one_only visibility_specified
  Same comdat group as: _ZNSt6vectorIS_IiSaIiEESaIS1_EED2Ev/3926
  References: _ZNSt6vectorIS_IiSaIiEESaIS1_EED2Ev/3926 (alias) 
  Referring: 
  Availability: available
  Function flags:
  Called by: main/3228 (0 (precise),0.00 per call) main/3228 (3042075 (estimated locally),1.00 per call) 
  Calls: 
_ZNSt6vectorIS_IiSaIiEESaIS1_EED2Ev/3926 (std::vector<_Tp, _Alloc>::~vector() [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]) @0x7f11404fb440
  Type: function definition analyzed
  Visibility: externally_visible public weak comdat comdat_group:_ZNSt6vectorIS_IiSaIiEESaIS1_EED5Ev one_only visibility_specified
  Same comdat group as: _ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev/3927
  References: 
  Referring: _ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev/3927 (alias) 
  Availability: available
  Function flags: count:118111600 (estimated locally) body
  Called by: 
  Calls: _ZNSt12_Vector_baseISt6vectorIiSaIiEESaIS2_EED2Ev/4337 (118111600 (estimated locally),1.00 per call) _ZNSt12_Vector_baseIiSaIiEED2Ev/4318 (955630225 (estimated locally),8.09 per call) 
_ZNSt6vectorIS_IiSaIiEESaIS1_EEC1EmRKS1_RKS2_/3924 (std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]) @0x7f11404fb220
  Type: function definition analyzed alias cpp_implicit_alias
  Visibility: externally_visible public weak comdat comdat_group:_ZNSt6vectorIS_IiSaIiEESaIS1_EEC5EmRKS1_RKS2_ one_only visibility_specified
  Same comdat group as: _ZNSt6vectorIS_IiSaIiEESaIS1_EEC2EmRKS1_RKS2_/3923
  References: _ZNSt6vectorIS_IiSaIiEESaIS1_EEC2EmRKS1_RKS2_/3923 (alias) 
  Referring: 
  Availability: available
  Function flags:
  Called by: main/3228 (3042075 (estimated locally),1.00 per call) 
  Calls: 
_ZNSt6vectorIS_IiSaIiEESaIS1_EEC2EmRKS1_RKS2_/3923 (std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]) @0x7f11404fb110
  Type: function definition analyzed
  Visibility: externally_visible public weak comdat comdat_group:_ZNSt6vectorIS_IiSaIiEESaIS1_EEC5EmRKS1_RKS2_ one_only visibility_specified
  Same comdat group as: _ZNSt6vectorIS_IiSaIiEESaIS1_EEC1EmRKS1_RKS2_/3924
  References: 
  Referring: _ZNSt6vectorIS_IiSaIiEESaIS1_EEC1EmRKS1_RKS2_/3924 (alias) 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body
  Called by: 
  Calls: _ZNSt12_Vector_baseISt6vectorIiSaIiEESaIS2_EED2Ev/4337 (0 (precise),0.00 per call) _ZNSt22__uninitialized_fill_nILb0EE15__uninit_fill_nIPSt6vectorIiSaIiEEmS4_EET_S6_T0_RKT1_/4823 (1073312329 (estimated locally),1.00 per call) _ZNSt12_Vector_baseISt6vectorIiSaIiEESaIS2_EE17_M_create_storageEm/4600 (1073312329 (estimated locally),1.00 per call) (can throw external) _ZSt20__throw_length_errorPKc/5467 (429496 (estimated locally),0.00 per call) (can throw external) 
_ZNSt6vectorIiSaIiEEC1EmRKiRKS0_/3912 (std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = int; _Alloc = std::allocator<int>]) @0x7f11404ef550
  Type: function definition analyzed alias cpp_implicit_alias
  Visibility: externally_visible public weak comdat comdat_group:_ZNSt6vectorIiSaIiEEC5EmRKiRKS0_ one_only visibility_specified
  Same comdat group as: _ZNSt6vectorIiSaIiEEC2EmRKiRKS0_/3911
  References: _ZNSt6vectorIiSaIiEEC2EmRKiRKS0_/3911 (alias) 
  Referring: 
  Availability: available
  Function flags:
  Called by: main/3228 (3042075 (estimated locally),1.00 per call) (can throw external) 
  Calls: 
_ZNSt6vectorIiSaIiEEC2EmRKiRKS0_/3911 (std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = int; _Alloc = std::allocator<int>]) @0x7f11404ef440
  Type: function definition analyzed
  Visibility: externally_visible public weak comdat comdat_group:_ZNSt6vectorIiSaIiEEC5EmRKiRKS0_ one_only visibility_specified
  Same comdat group as: _ZNSt6vectorIiSaIiEEC1EmRKiRKS0_/3912
  References: 
  Referring: _ZNSt6vectorIiSaIiEEC1EmRKiRKS0_/3912 (alias) 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body
  Called by: 
  Calls: _ZNSt6vectorIiSaIiEE18_M_fill_initializeEmRKi/4320 (1073312329 (estimated locally),1.00 per call) _ZNSt12_Vector_baseIiSaIiEE17_M_create_storageEm/4588 (1073312329 (estimated locally),1.00 per call) (can throw external) _ZSt20__throw_length_errorPKc/5467 (429496 (estimated locally),0.00 per call) (can throw external) 
main/3228 (int main()) @0x7f1140dfdee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: _ZSt3cin/5463 (addr) _ZSt4cout/5465 (addr) 
  Referring: 
  Availability: available
  Function flags: count:3042075 (estimated locally) body only_called_at_startup executed_once
  Called by: 
  Calls: _ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev/3927 (0 (precise),0.00 per call) _ZNSt12_Vector_baseIiSaIiEED2Ev/4318 (0 (precise),0.00 per call) _ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev/3927 (3042075 (estimated locally),1.00 per call) _ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l/5478 (3042075 (estimated locally),1.00 per call) _ZNSolsEi/5464 (3042075 (estimated locally),1.00 per call) _ZNSt12_Vector_baseIiSaIiEED2Ev/4318 (3042075 (estimated locally),1.00 per call) _ZNSt6vectorIS_IiSaIiEESaIS1_EEC1EmRKS1_RKS2_/3924 (3042075 (estimated locally),1.00 per call) _ZNSt6vectorIiSaIiEEC1EmRKiRKS0_/3912 (3042075 (estimated locally),1.00 per call) (can throw external) _ZNSirsERi/5462 (3042075 (estimated locally),1.00 per call) (can throw external) _ZNSirsERi/5462 (3042075 (estimated locally),1.00 per call) (can throw external) 
_ZStL8__ioinit/1878 (std::ios_base::Init std::__ioinit) @0x7f11447d8400
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: _Z41__static_initialization_and_destruction_0ii.constprop.0/5531 (addr) _Z41__static_initialization_and_destruction_0ii.constprop.0/5531 (addr) 
  Availability: available
  Varpool flags:

;; Function std::vector<std::vector<int> >::~vector (_ZNSt6vectorIS_IiSaIiEESaIS1_EED2Ev, funcdef_no=10586, decl_uid=213781, cgraph_uid=3244, symbol_order=3926)

Modification phase of node std::vector<_Tp, _Alloc>::~vector() [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/3926
void std::vector<std::vector<int> >::~vector (struct vector * const this)
{
  struct vector * __first;
  struct vector * _1;
  struct vector * _2;
  struct _Vector_base * _3;
  struct _Vector_base * _9;

  <bb 2> [local count: 118111600]:
  _1 = this_4(D)->D.213784._M_impl.D.213129._M_finish;
  _2 = this_4(D)->D.213784._M_impl.D.213129._M_start;
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630225]:
  _9 = &__first_6->D.182734;
  std::_Vector_base<int, std::allocator<int> >::~_Vector_base (_9);
  *__first_6 ={v} {CLOBBER};
  __first_10 = __first_6 + 24;

  <bb 4> [local count: 1073741824]:
  # __first_6 = PHI <_2(2), __first_10(3)>
  if (_1 != __first_6)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111600]:
  _3 = &this_4(D)->D.213784;
  std::_Vector_base<std::vector<int>, std::allocator<std::vector<int> > >::~_Vector_base (_3);
  *this_4(D) ={v} {CLOBBER};
  return;

}



;; Function std::_Vector_base<int, std::allocator<int> >::~_Vector_base (_ZNSt12_Vector_baseIiSaIiEED2Ev, funcdef_no=10958, decl_uid=182190, cgraph_uid=3616, symbol_order=4318)

Modification phase of node std::_Vector_base<_Tp, _Alloc>::~_Vector_base() [with _Tp = int; _Alloc = std::allocator<int>]/4318
void std::_Vector_base<int, std::allocator<int> >::~_Vector_base (struct _Vector_base * const this)
{
  int * _1;
  int * _2;
  long int _3;
  long unsigned int _7;

  <bb 2> [local count: 1073741824]:
  _1 = this_5(D)->_M_impl.D.182080._M_end_of_storage;
  _2 = this_5(D)->_M_impl.D.182080._M_start;
  _3 = _1 - _2;
  if (_2 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129753]:
  _7 = (long unsigned int) _3;
  operator delete (_2, _7);

  <bb 4> [local count: 1073741824]:
  *this_5(D) ={v} {CLOBBER};
  return;

}



;; Function std::vector<std::vector<int> >::vector (_ZNSt6vectorIS_IiSaIiEESaIS1_EEC2EmRKS1_RKS2_, funcdef_no=10583, decl_uid=213755, cgraph_uid=3241, symbol_order=3923)

Modification phase of node std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]/3923
void std::vector<std::vector<int> >::vector (struct vector * const this, size_type __n, const struct value_type & __value, const struct allocator_type & __a)
{
  struct _Vector_base * _1;
  struct vector * _9;
  struct vector * _10;

  <bb 2> [local count: 1073741824]:
  *this_3(D) ={v} {CLOBBER};
  _1 = &this_3(D)->D.213784;
  if (__n_5(D) > 384307168202282325)
    goto <bb 3>; [0.04%]
  else
    goto <bb 4>; [99.96%]

  <bb 3> [local count: 429496]:
  std::__throw_length_error ("cannot create std::vector larger than max_size()");

  <bb 4> [local count: 1073312329]:
  MEM[(struct _Vector_impl_data *)this_3(D)] ={v} {CLOBBER};
  MEM[(struct _Vector_impl_data *)this_3(D)]._M_start = 0B;
  MEM[(struct _Vector_impl_data *)this_3(D)]._M_finish = 0B;
  MEM[(struct _Vector_impl_data *)this_3(D)]._M_end_of_storage = 0B;
  std::_Vector_base<std::vector<int>, std::allocator<std::vector<int> > >::_M_create_storage (_1, __n_5(D));
  _9 = *this_3(D).D.213784._M_impl.D.213129._M_start;
  _10 = std::__uninitialized_fill_n<false>::__uninit_fill_n<std::vector<int>*, long unsigned int, std::vector<int> > (_9, __n_5(D), __value_7(D));

  <bb 5> [local count: 1073312329]:
  *this_3(D).D.213784._M_impl.D.213129._M_finish = _10;
  return;

  <bb 6> [count: 0]:
<L0>:
  std::_Vector_base<std::vector<int>, std::allocator<std::vector<int> > >::~_Vector_base (_1);
  resx 1

}



;; Function main (main, funcdef_no=9898, decl_uid=212622, cgraph_uid=2557, symbol_order=3228) (executed once)

Modification phase of node int main()/3228
int main ()
{
  char __c;
  int k;
  int k;
  int j;
  int i;
  int i;
  struct vector dp;
  int b;
  int a;
  const int D.213874;
  const int D.213872;
  const value_type D.213805;
  struct allocator_type D.213807;
  struct vector D.213808;
  struct allocator_type D.213864;
  int b.0_1;
  int _2;
  long unsigned int _3;
  int a.1_4;
  int _5;
  long unsigned int _6;
  long unsigned int _7;
  int _8;
  int _9;
  long unsigned int _10;
  long unsigned int _11;
  int _12;
  int _13;
  long unsigned int _14;
  int _15;
  int _16;
  long unsigned int _17;
  int _18;
  long unsigned int _19;
  long unsigned int _20;
  int _21;
  int _22;
  int _23;
  long unsigned int _24;
  int _25;
  int _26;
  long unsigned int _27;
  int _28;
  long unsigned int _29;
  int b.3_30;
  int a.4_31;
  int a.4_32;
  long unsigned int _33;
  int b.6_34;
  long unsigned int _35;
  int _36;
  struct __istream_type & _51;
  value_type & _53;
  int * _60;
  value_type & _62;
  long unsigned int _63;
  struct basic_ostream & _65;
  const int & _72;
  int _74;
  int _75;
  struct value_type & _76;
  long unsigned int _77;
  struct vector * _78;
  value_type & _82;
  int * _83;
  const int & _84;
  int _86;
  struct value_type & _91;
  long unsigned int _92;
  int * _95;
  long unsigned int _96;
  struct value_type & _97;
  int * _98;
  long unsigned int _99;
  value_type & _100;
  struct vector * _101;
  long unsigned int _102;
  struct value_type & _103;
  long unsigned int _104;
  value_type & _105;
  int _106;
  const int & _107;
  long unsigned int _108;
  value_type & _109;
  int * _110;
  long unsigned int _111;
  value_type & _112;
  struct value_type & _113;
  int * _114;
  long unsigned int _115;
  value_type & _116;
  struct vector * _117;
  long unsigned int _118;
  struct value_type & _119;
  int * _120;
  long unsigned int _121;
  value_type & _122;
  struct vector * _123;
  long unsigned int _124;
  struct value_type & _125;

  <bb 2> [local count: 3042075]:
  _51 = std::basic_istream<char>::operator>> (&cin, &a);
  std::basic_istream<char>::operator>> (_51, &b);
  D.213805 = 1000000000;
  b.0_1 = b;
  _2 = b.0_1 + 1;
  _3 = (long unsigned int) _2;
  std::vector<int>::vector (&D.213808, _3, &D.213805, &D.213807);
  a.1_4 = a;
  _5 = a.1_4 + 1;
  _6 = (long unsigned int) _5;
  std::vector<std::vector<int> >::vector (&dp, _6, &D.213808, &D.213864);

  <bb 3> [local count: 3042075]:
  std::_Vector_base<int, std::allocator<int> >::~_Vector_base (&D.213808.D.182734);
  D.213808 ={v} {CLOBBER};
  D.213808 ={v} {CLOBBER};
  D.213805 ={v} {CLOBBER};
  D.213807 ={v} {CLOBBER};
  D.213864 ={v} {CLOBBER};
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 24613156]:
  _7 = (long unsigned int) i_37;
  _78 = dp.D.213784._M_impl.D.213129._M_start;
  _77 = _7 * 24;
  _76 = _78 + _77;
  _95 = MEM[(struct vector *)_76].D.182734._M_impl.D.182080._M_start;
  _63 = _7 * 4;
  _62 = _95 + _63;
  *_62 = 0;
  i_94 = i_37 + 1;

  <bb 5> [local count: 27655232]:
  # i_37 = PHI <0(3), i_94(4)>
  _75 = b;
  _74 = a;
  if (_74 > _75)
    goto <bb 6>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 6> [local count: 9402779]:

  <bb 7> [local count: 27655232]:
  # _72 = PHI <&a(5), &b(6)>
  _8 = *_72;
  if (_8 >= i_37)
    goto <bb 4>; [89.00%]
  else
    goto <bb 27>; [11.00%]

  <bb 27> [local count: 3042075]:
  goto <bb 21>; [100.00%]

  <bb 8> [local count: 199142810]:
  if (i_38 == j_39)
    goto <bb 9>; [40.69%]
  else
    goto <bb 30>; [59.31%]

  <bb 30> [local count: 118111600]:
  goto <bb 13>; [100.00%]

  <bb 9> [local count: 81031210]:
  // predicted unlikely by continue predictor.
  goto <bb 18>; [100.00%]

  <bb 10> [local count: 955630226]:
  _9 = i_38 - k_40;
  _10 = (long unsigned int) _9;
  _101 = dp.D.213784._M_impl.D.213129._M_start;
  _102 = _10 * 24;
  _103 = _101 + _102;
  _11 = (long unsigned int) j_39;
  _98 = MEM[(struct vector *)_103].D.182734._M_impl.D.182080._M_start;
  _99 = _11 * 4;
  _100 = _98 + _99;
  _12 = *_100;
  _13 = _12 + 1;
  _14 = (long unsigned int) k_40;
  _96 = _14 * 24;
  _97 = _101 + _96;
  _60 = MEM[(struct vector *)_97].D.182734._M_impl.D.182080._M_start;
  _53 = _60 + _99;
  _15 = *_53;
  _16 = _13 + _15;
  D.213872 = _16;
  _17 = (long unsigned int) i_38;
  _92 = _17 * 24;
  _91 = _101 + _92;
  _83 = MEM[(struct vector *)_91].D.182734._M_impl.D.182080._M_start;
  _82 = _83 + _99;
  _86 = MEM[(const int &)_82];
  if (_16 < _86)
    goto <bb 11>; [34.00%]
  else
    goto <bb 12>; [66.00%]

  <bb 11> [local count: 324914280]:

  <bb 12> [local count: 955630226]:
  # _84 = PHI <_82(10), &D.213872(11)>
  _18 = *_84;
  *_82 = _18;
  D.213872 ={v} {CLOBBER};
  k_89 = k_40 + 1;

  <bb 13> [local count: 1073741824]:
  # k_40 = PHI <1(30), k_89(12)>
  if (i_38 > k_40)
    goto <bb 10>; [89.00%]
  else
    goto <bb 29>; [11.00%]

  <bb 29> [local count: 118111600]:
  goto <bb 17>; [100.00%]

  <bb 14> [local count: 955630226]:
  _19 = (long unsigned int) i_38;
  _117 = dp.D.213784._M_impl.D.213129._M_start;
  _118 = _19 * 24;
  _119 = _117 + _118;
  _20 = (long unsigned int) k_41;
  _114 = MEM[(struct vector *)_119].D.182734._M_impl.D.182080._M_start;
  _115 = _20 * 4;
  _116 = _114 + _115;
  _21 = *_116;
  _22 = _21 + 1;
  _113 = _117 + _118;
  _23 = j_39 - k_41;
  _24 = (long unsigned int) _23;
  _110 = MEM[(struct vector *)_113].D.182734._M_impl.D.182080._M_start;
  _111 = _24 * 4;
  _112 = _110 + _111;
  _25 = *_112;
  _26 = _22 + _25;
  D.213874 = _26;
  _27 = (long unsigned int) j_39;
  _108 = _27 * 4;
  _109 = _110 + _108;
  _106 = MEM[(const int &)_109];
  if (_26 < _106)
    goto <bb 15>; [34.00%]
  else
    goto <bb 16>; [66.00%]

  <bb 15> [local count: 324914280]:

  <bb 16> [local count: 955630226]:
  # _107 = PHI <_109(14), &D.213874(15)>
  _28 = *_107;
  _29 = (long unsigned int) j_39;
  _104 = _29 * 4;
  _105 = _110 + _104;
  *_105 = _28;
  D.213874 ={v} {CLOBBER};
  k_81 = k_41 + 1;

  <bb 17> [local count: 1073741824]:
  # k_41 = PHI <1(29), k_81(16)>
  if (j_39 > k_41)
    goto <bb 14>; [89.00%]
  else
    goto <bb 18>; [11.00%]

  <bb 18> [local count: 199142810]:
  j_90 = j_39 + 1;

  <bb 19> [local count: 223755966]:
  # j_39 = PHI <1(28), j_90(18)>
  b.3_30 = b;
  if (b.3_30 >= j_39)
    goto <bb 8>; [89.00%]
  else
    goto <bb 20>; [11.00%]

  <bb 20> [local count: 24613156]:
  i_71 = i_38 + 1;

  <bb 21> [local count: 27655232]:
  # i_38 = PHI <1(27), i_71(20)>
  a.4_31 = a;
  if (a.4_31 >= i_38)
    goto <bb 28>; [89.00%]
  else
    goto <bb 22>; [11.00%]

  <bb 28> [local count: 24613156]:
  goto <bb 19>; [100.00%]

  <bb 22> [local count: 3042075]:
  # a.4_32 = PHI <a.4_31(21)>
  _33 = (long unsigned int) a.4_32;
  _123 = dp.D.213784._M_impl.D.213129._M_start;
  _124 = _33 * 24;
  _125 = _123 + _124;
  b.6_34 = b;
  _35 = (long unsigned int) b.6_34;
  _120 = MEM[(struct vector *)_125].D.182734._M_impl.D.182080._M_start;
  _121 = _35 * 4;
  _122 = _120 + _121;
  _36 = *_122;
  _65 = std::basic_ostream<char>::operator<< (&cout, _36);

  <bb 23> [local count: 3042075]:
  __c = 10;
  std::__ostream_insert<char, std::char_traits<char> > (_65, &__c, 1);

  <bb 24> [local count: 3042075]:
  __c ={v} {CLOBBER};
  std::vector<std::vector<int> >::~vector (&dp);
  a ={v} {CLOBBER};
  b ={v} {CLOBBER};
  dp ={v} {CLOBBER};
  return 0;

  <bb 25> [count: 0]:
<L21>:
  std::_Vector_base<int, std::allocator<int> >::~_Vector_base (&D.213808.D.182734);
  D.213808 ={v} {CLOBBER};
  resx 9

  <bb 26> [count: 0]:
<L29>:
  std::vector<std::vector<int> >::~vector (&dp);
  resx 22

}



;; Function _GLOBAL__sub_I_main (_GLOBAL__sub_I_main, funcdef_no=11743, decl_uid=233682, cgraph_uid=4401, symbol_order=5461) (executed once)

Modification phase of node (static initializers for rc.cpp)/5461
void _GLOBAL__sub_I_main ()
{
  <bb 2> [local count: 1073741824]:
  __static_initialization_and_destruction_0 (1, 65535);
  return;

}


