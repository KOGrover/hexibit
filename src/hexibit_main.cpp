#include "MainUtils.h"

#include "config/Config.h"
#include "data/HexStringReader.h"
#include "data/IDataReader.h"
#include "parse/Interpreter.h"
#include "print/ListPrinter.h"

int main(int argc, char* argv[]) {
  // Parsing the configuration
  const hx::Config cfg(argc, argv);
  cfg.print();
  //TODO: validate and print usage if invalid

  // Creating the buffer holding the data to interpret
  hx::IDataReader* reader = nullptr;
  if (!cfg.hex_string_.empty()) {
    reader = new hx::HexStringReader(cfg.hex_string_, cfg.byte_order_);
  } else if (!cfg.filepath_.empty()) {
    _DEATH("Reading from file is not available yet");
  } else {
    _DEATH("Invalid config");
  }

  // Creating the interpreter and the printer
  hx::Interpreter interpreter(reader, &cfg.interpretations_);
  hx::IConsolePrinter* printer = new hx::ListPrinter();

  // Interpreting the data
  interpreter.performInterpretation(printer);

  delete printer;
  delete reader;
  return 0;
}
