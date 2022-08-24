# !/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RESET='\033[0m'

echo "${BLUE}========Norm Test========${RESET}"
NORM_RESULT=$(norminette | grep "Error:")
if [ "$NORM_RESULT" = "" ];
then
	echo "${GREEN}Norm pass${RESET}"
else
	echo "${RED}Norm fail${RESET}"
	echo "${RED}test failed :(${RESET}"
	exit 1
fi

echo "${BLUE}==========ex00==========${RESET}"
cd ex00 && make -s && echo "${GREEN}ex00 compile pass${RESET}"

EX00_FILE=$(find . -name "RGB2BGR")
if [ "$EX00_FILE" = "" ];
then
	echo "${RED}ex00 file not found${RESET}"
	echo "${RED}test failed :(${RESET}"
fi

./RGB2BGR
EX00_DIFF_RESULT=$(diff ./original.bmp ../img/original.bmp)
if [ "$EX00_DIFF_RESULT" = "" ];
then
	echo "${GREEN}ex00 diff pass${RESET}"
else
	echo "${RED}ex00 diff fail${RESET}"
	echo "${RED}test failed :(${RESET}"
	exit 1
fi

echo "${BLUE}==========ex01==========${RESET}"
cd ../ex01 && make -s && echo "${GREEN}ex01 compile pass${RESET}"

EX01_FILE=$(find . -name "reverse")
if [ "$EX01_FILE" = "" ];
then
	echo "${RED}ex01 file not found${RESET}"
	echo "${RED}test failed :(${RESET}"
fi

./reverse
EX01_DIFF_RESULT=$(diff ./original.bmp ../img/original.bmp)
if [ "$EX01_DIFF_RESULT" = "" ];
then
	echo "${GREEN}ex01 diff pass${RESET}"
else
	echo "${RED}ex01 diff fail${RESET}"
	echo "${RED}test failed :(${RESET}"
	exit 1
fi

echo "${BLUE}==========ex02==========${RESET}"
cd ../ex02 && make -s && echo "${GREEN}ex02 compile pass${RESET}"

EX02_FILE=$(find . -name "zoom")
if [ "$EX02_FILE" = "" ];
then
	echo "${RED}ex02 file not found${RESET}"
	echo "${RED}test failed :(${RESET}"
	exit 1
fi
./zoom
echo "\n${GREEN}test all passed :)${RESET}"
