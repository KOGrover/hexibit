#pragma once

#include <string>

#include "Interpretation.h"
#include "IConsolePrinter.h"

namespace hx {

class ListPrinter : public IConsolePrinter {
  void printHeader() override;

  void printFooter() override;

  void printInterpretation(const std::string& hex_data, const Interpretation& interpretation, const std::string& interpreted_value_str) override;

};

} // namespace hx
