# !/bin/bash

# color
RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
RESET='\033[0m'

# norm test
echo "${YELLOW}========Norm Test========${RESET}"
NORM_RESULT=$(norminette | grep "Error:")
if [ "$NORM_RESULT" = "" ];
then
	echo "${GREEN}Norm pass${RESET}"
else
	echo "${RED}Norm fail${RESET}"
	printf "${RED}Test failed :( ❌${RESET}\n"
	exit 1
fi

echo "${YELLOW}==========Ex00==========${RESET}"
# ex00 make
cd ex00 && make fclean -s && make -s

# ex00 compile test
status=$?
if [ $status -eq 0 ];
then
	echo "${GREEN}Ex00 compile pass${RESET}"
else
	echo "${RED}Ex00 compile fail${RESET}"
	printf "${RED}Test failed :( ❌${RESET}\n"
	exit 1
fi

# ex00 output file name test
EX00_FILE=$(find . -name "RGB2BGR")
if [ "$EX00_FILE" = "" ];
then
	echo "${RED}RGB2BGR file not found${RESET}"
	printf "${RED}Test failed :( ❌${RESET}\n"
	exit 1
fi

# ex00 output file execute test
./RGB2BGR
status=$?
if [ $status -gt 0 ];
then
	echo "${RED}RGB2BGR execute fail${RESET}"
	printf "${RED}Test failed :( ❌${RESET}\n"
	exit 1
fi

# ex00 diff test
EX00_DIFF_RESULT=$(diff ./original.bmp ../img/original.bmp)
if [ "$EX00_DIFF_RESULT" = "" ];
then
	echo "${GREEN}Ex00 diff pass${RESET}"
else
	echo "${RED}Ex00 diff fail${RESET}"
	printf "${RED}Test failed :( ❌${RESET}\n"
	exit 1
fi

echo "${YELLOW}==========Ex01==========${RESET}"
# ex01 compile test
cd ../ex01 && make fclean -s && make -s
status=$?
if [ $status -eq 0 ];
then
	echo "${GREEN}Ex01 compile pass${RESET}"
else
	echo "${RED}Ex01 compile fail${RESET}"
	printf "${RED}Test failed :( ❌${RESET}\n"
	exit 1
fi

# ex01 file name test
EX01_FILE=$(find . -name "reverse")
if [ "$EX01_FILE" = "" ];
then
	echo "${RED}reverse file not found${RESET}"
	printf "${RED}Test failed :( ❌${RESET}\n"
fi

# ex01 file execute test
./reverse
status=$?
if [ $status -gt 0 ];
then
	echo "${RED}reverse file execute fail${RESET}"
	printf "${RED}Test failed :( ❌${RESET}\n"
fi

# ex01 diff test
EX01_DIFF_RESULT=$(diff ./original.bmp ../img/original.bmp)
if [ "$EX01_DIFF_RESULT" = "" ];
then
	echo "${GREEN}Ex01 diff pass${RESET}"
else
	echo "${RED}Ex01 diff fail${RESET}"
	printf "${RED}Test failed :( ❌${RESET}\n"
	exit 1
fi

echo "${YELLOW}==========Ex02==========${RESET}"
# ex02 compile test
cd ../ex02 && make fclean -s && make -s
status=$?
if [ $status -eq 0 ];
then
	echo "${GREEN}Ex02 compile pass${RESET}"
else
	echo "${RED}Ex02 compile fail${RESET}"
	printf "${RED}Test failed :( ❌${RESET}\n"
	exit 1
fi

# ex02 file name test
EX02_FILE=$(find . -name "zoom")
if [ "$EX02_FILE" = "" ];
then
	echo "${RED}zoom file not found${RESET}"
	printf "${RED}Test failed :( ❌${RESET}\n"
	exit 1
fi

# ex02 file execute test
./zoom
status=$?
if [ $status -gt 0 ];
then
	echo "${RED}zoom file execute failed${RESET}"
	printf "${RED}Test failed :( ❌${RESET}\n"
fi

printf "\n${GREEN}Test all passed :)${RESET} ✅\n"
