#!/bin/bash

flex -Pdnayy -o dnaLexer.cxx.prebuilt dnaLexer.lxx
bison -y -d -p dnayy -o dnaParser.cxx.prebuilt dnaParser.yxx
