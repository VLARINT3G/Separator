#include <Separator.h>

Separator::Separator(const std::string &subStr) : subStr_(subStr), first_(false) {}

std::string Separator::Get() const {
  if (first_) {
    return {};
  }
  first_ = true;
  return subStr_;
}
