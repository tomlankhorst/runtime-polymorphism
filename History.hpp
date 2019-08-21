#pragma once

#include "Document.hpp"

#include <cassert>
#include <vector>

using history_t = std::vector<document_t>;

void commit(history_t& x) { assert(!x.empty()); x.push_back(x.back()); }
void undo(history_t& x) { assert(!x.empty()); x.pop_back(); }
document_t& current(history_t& x) { assert(!x.empty()); return x.back(); }
