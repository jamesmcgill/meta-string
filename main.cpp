#include <cstdio>
#include <iostream>

//------------------------------------------------------------------------------
template <std::size_t SZ>
class _StringLiteral
{
  char m_array[SZ] = {};

public:
  constexpr _StringLiteral(const char (&literal)[SZ])
  {
    for (std::size_t i = 0; i < SZ; ++i)
    {
      m_array[i] = literal[i];
    }
  }

  template <std::size_t LSZ, std::size_t RSZ>
  constexpr _StringLiteral(
    const _StringLiteral<LSZ>& s1, const _StringLiteral<RSZ>& s2)
  {
    const std::size_t lhsEnd = LSZ - 1;    // NB: -1 to remove null terminator
    for (std::size_t i = 0; i < lhsEnd; ++i)
    {
      m_array[i] = s1[i];
    }

    for (std::size_t i = 0; i < RSZ; ++i)
    {
      m_array[lhsEnd + i] = s2[i];
    }
  }

  constexpr char operator[](std::size_t i) const noexcept
  {
    return (i < SZ) ? m_array[i] : 0;
  }

  constexpr std::size_t size() const noexcept { return (SZ != 0) ? SZ - 1 : 0; }

  constexpr const char* c_str() const noexcept { return m_array; }
};

//------------------------------------------------------------------------------
template <std::size_t N1, std::size_t N2>
constexpr auto
operator+(const _StringLiteral<N1>& s1, const _StringLiteral<N2>& s2)
  -> _StringLiteral<N1 + N2 - 1>
{
  return _StringLiteral<N1 + N2 - 1>(s1, s2);
}

//------------------------------------------------------------------------------
// Deduction helper function for MSVC (class template deduction still missing)
template <std::size_t SZ>
constexpr auto
StringLiteral(const char (&literal)[SZ]) -> _StringLiteral<SZ>
{
  return _StringLiteral<SZ>(literal);
}

//------------------------------------------------------------------------------
int
main()
{
  constexpr auto s1 = StringLiteral("Hello, ");
  constexpr auto s2 = StringLiteral("World!");
  constexpr auto s3 = StringLiteral(" (again)");

  constexpr auto sCon1 = s1 + s2;
  constexpr auto sCon2 = s1 + s2 + s3;
  constexpr auto sCon3 = sCon1 + s3;

  std::cout << s1.c_str() << '\n';
  std::cout << "length is " << s1.size() << '\n';

  std::cout << s2.c_str() << '\n';
  std::cout << "length is " << s2.size() << '\n';

  std::cout << s3.c_str() << '\n';
  std::cout << "length is " << s3.size() << '\n';

  std::cout << '\n';

  std::cout << sCon1.c_str() << '\n';
  std::cout << "length is " << sCon1.size() << '\n';

  std::cout << sCon2.c_str() << '\n';
  std::cout << "length is " << sCon2.size() << '\n';

  std::cout << sCon3.c_str() << '\n';
  std::cout << "length is " << sCon3.size() << '\n';

  return 0;
}

//------------------------------------------------------------------------------
