#ifndef IS_PRINTABLE_HPP_
# define IS_PRINTABLE_HPP_

template<typename S, typename O>
class is_printable
{
private:
	typedef char	yes[1];
	typedef char	no[2];

	template<std::size_t>
	struct IsPrintableWrap {
		typedef void *value;
	};

	template<typename C>
	static yes &isPrintable(typename IsPrintableWrap<sizeof(
			(*reinterpret_cast<S *>(NULL))
			<< (*reinterpret_cast<C *>(NULL)))>::value value);

	template <typename>
	static no &isPrintable(...);

public:
	enum { Value = sizeof(isPrintable<O>(NULL)) == sizeof(yes) };
};

#endif
