#ifndef IsPod_h
#define IsPod_h

/// Type traits. Struct template that allows user to check if 
/// T if simple type (POD). This one works if
/// T is not POD. Rest of implementation (for
/// POD types) is in main.cpp file. 
template <typename T>
struct is_pod
{
	const static bool pod = false;
};

#endif