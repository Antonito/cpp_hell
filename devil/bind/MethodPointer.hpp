#ifndef METHOD_POINTER_HPP_
#define METHOD_POINTER_HPP_

template <class ClassType, typename ReturnType>
class MethodPointer;

template <class ClassType, typename ReturnType>
class MethodPointer<ClassType, ReturnType (ClassType::*)()>
{
public:
	MethodPointer(ClassType *ptr,
		ReturnType (ClassType::*meth)()) :
		 _classInstance(ptr), _meth(meth)
	{
	}

	ReturnType operator()()
	{
		return (_classInstance->*_meth)();
	}

private:
	ClassType *_classInstance;
	ReturnType (ClassType::*_meth)();
};

template <class ClassType, typename ReturnType, typename T1>
class MethodPointer<ClassType, ReturnType (ClassType::*)(T1)>
{
public:
	MethodPointer(ClassType *ptr,
		ReturnType (ClassType::*meth)(T1)) :
		 _classInstance(ptr), _meth(meth)
	{
	}

	ReturnType operator()(T1 t1)
	{
		return (_classInstance->*_meth)(t1);
	}

private:
	ClassType *_classInstance;
	ReturnType (ClassType::*_meth)(T1);
};

template <class ClassType, typename ReturnType, typename T1, typename T2>
class MethodPointer<ClassType, ReturnType (ClassType::*)(T1, T2)>
{
public:
	MethodPointer(ClassType *ptr,
		ReturnType (ClassType::*meth)(T1, T2)) :
		 _classInstance(ptr), _meth(meth)
	{
	}

	ReturnType operator()(T1 t1, T2 t2)
	{
		return (_classInstance->*_meth)(t1, t2);
	}

private:
	ClassType *_classInstance;
	ReturnType (ClassType::*_meth)(T1, T2);
};

template <class ClassType, typename ReturnType, typename T1, typename T2,
	typename T3>
class MethodPointer<ClassType, ReturnType (ClassType::*)(T1, T2, T3)>
{
public:
	MethodPointer(ClassType *ptr,
		ReturnType (ClassType::*meth)(T1, T2, T3)) :
		 _classInstance(ptr), _meth(meth)
	{
	}

	ReturnType operator()(T1 t1, T2 t2, T3 t3)
	{
		return (_classInstance->*_meth)(t1, t2, t3);
	}

private:
	ClassType *_classInstance;
	ReturnType (ClassType::*_meth)(T1, T2, T3);
};

template <class ClassType, typename ReturnType, typename T1, typename T2,
	typename T3, typename T4>
class MethodPointer<ClassType, ReturnType (ClassType::*)(T1, T2, T3, T4)>
{
public:
	MethodPointer(ClassType *ptr,
		ReturnType (ClassType::*meth)(T1, T2, T3, T4)) :
		 _classInstance(ptr), _meth(meth)
	{
	}

	ReturnType operator()(T1 t1, T2 t2, T3 t3, T4 t4)
	{
		return (_classInstance->*_meth)(t1, t2, t3, t4);
	}

private:
	ClassType *_classInstance;
	ReturnType (ClassType::*_meth)(T1, T2, T3, T4);
};

template <class ClassType, typename ReturnType, typename T1, typename T2,
	typename T3, typename T4, typename T5>
class MethodPointer<ClassType,
		ReturnType (ClassType::*)(T1, T2, T3, T4, T5)>
{
public:
	MethodPointer(ClassType *ptr,
		ReturnType (ClassType::*meth)(T1, T2, T3, T4, T5)) :
		 _classInstance(ptr), _meth(meth)
	{
	}

	ReturnType operator()(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5)
	{
		return (_classInstance->*_meth)(t1, t2, t3, t4, t5);
	}

private:
	ClassType *_classInstance;
	ReturnType (ClassType::*_meth)(T1, T2, T3, T4, T5);
};

template <class ClassType, typename ReturnType, typename T1, typename T2,
	typename T3, typename T4, typename T5, typename T6>
class MethodPointer<ClassType,
		ReturnType (ClassType::*)(T1, T2, T3, T4, T5, T6)>
{
public:
	MethodPointer(ClassType *ptr,
		ReturnType (ClassType::*meth)(T1, T2, T3, T4, T5, T6)) :
		 _classInstance(ptr), _meth(meth)
	{
	}

	ReturnType operator()(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6)
	{
		return (_classInstance->*_meth)(t1, t2, t3, t4, t5, t6);
	}

private:
	ClassType *_classInstance;
	ReturnType (ClassType::*_meth)(T1, T2, T3, T4, T5, T6);
};

#endif
