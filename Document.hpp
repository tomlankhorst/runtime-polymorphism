#pragma once

#include "Object.hpp"

#include <vector>

using document_t = std::vector<object_t>;

void draw(const document_t& x, std::ostream& out, size_t position) {
  out << std::string(position, ' ') << "<document>" << std::endl;
  for (const auto &e : x)
    draw(e, out, position + 1);
  out << std::string(position, ' ') << "</document>" << std::endl;
}
