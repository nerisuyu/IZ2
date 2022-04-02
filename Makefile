check:
	./linters/run.sh

build:
	cmake -S ./project -B ./project/build
	make --directory=./project/build

build_test:
	

test:
	./project/build/tests/test_email_finder

install_gtest:
	mkdir gtest 
	git clone https://github.com/google/googletest.git gtest
	cmake -S gtest -B gtest/build
	cmake --build gtest/build
	sudo cmake --install gtest/build

run:
	./project/build/email_finder