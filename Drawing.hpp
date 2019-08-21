#pragma once

// Specialized draw implementation
template <typename IntegralDrawable>
std::enable_if_t<std::is_integral<IntegralDrawable>::value>
draw(const IntegralDrawable& d, std::ostream& out, size_t position) {
  out << std::string(position, ' ') << "int: " << d << std::endl;
}

// Default draw implementation
template <typename Drawable>
std::enable_if_t<!std::is_integral<Drawable>::value>
draw(const Drawable& d, std::ostream& out, size_t position) {
  out << std::string(position, ' ') << "gen: " << d << std::endl;
}

