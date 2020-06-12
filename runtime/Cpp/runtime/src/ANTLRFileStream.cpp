/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#include "support/StringUtils.h"

#include "ANTLRFileStream.h"

using namespace antlr4;

#if __cplusplus >= 201703L
ANTLRFileStream::ANTLRFileStream(std::string_view fileName) {
#else
ANTLRFileStream::ANTLRFileStream(const std::string &fileName) {
#endif
  _fileName = fileName;
  loadFromFile(fileName);
}

void ANTLRFileStream::loadFromFile(const std::string &fileName) {
  _fileName = fileName;
  if (_fileName.empty()) {
    return;
  }

#ifdef _MSC_VER
  std::ifstream stream(antlrcpp::s2ws(fileName), std::ios::binary);
#else
  std::ifstream stream(fileName, std::ios::binary);
#endif

  ANTLRInputStream::load(stream);
}

std::string ANTLRFileStream::getSourceName() const {
  return _fileName;
}
