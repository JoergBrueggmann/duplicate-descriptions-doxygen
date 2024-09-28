
#ifndef string_h
#define string_h


#include <string>
#include <variant>
#include <vector>


namespace cmn {


/**
 * \brief an empty type to indicate that things are equal.
 *
 * Used in variant templates to represent an alternative. This type is used in compare().
 */
class Equal
{
};

/**
 * \brief  checks whether two strings are equal and if not than provides the position where the two strings have its first different character / byte.
 * \param[in] sA 'String' to be compared with sB
 * \param[in] sB 'String' to be compared with sA
 * \return either Equal or position of difference
 */
std::variant<Equal, size_t> compare( std::string sA, std::string sB );


} // namespace cmn


#endif // string_h
