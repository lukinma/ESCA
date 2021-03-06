#pragma once

#include <vector>
#include <llvm/IR/Function.h>
// Sort functions in topological order.
// Callee goes before caller.
std::vector<llvm::Function const *> sort_functions(std::vector<llvm::Function const *> const &);
