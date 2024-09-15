#!/bin/bash

cd ai_help
sh keygen.sh
cd key
rm -f file*
cd ..
sh unifier.sh

