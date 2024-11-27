# this build rule add all features from product
all:
	cmake -S . -B build -DSUM=ON -DSUB=ON -DMUL=ON -DDIV=ON -DMOD=ON
	cmake --build build
# this build rule removes all features from products
none: 
	cmake -S . -B build -DSUM=OFF -DSUB=OFF -DMUL=OFF -DDIV=OFF -DMOD=OFF
	cmake --build build
# this build rule enables div feature only
div_on:
	cmake -S . -B build -DSUM=OFF -DSUB=OFF -DMUL=OFF -DDIV=ON -DMOD=OFF
	cmake --build build
# this build rule disables div feature only
div_off:
	cmake -S . -B build -DSUM=ON -DSUB=ON -DMUL=ON -DDIV=OFF -DMOD=ON
	cmake --build build
# this build rule enables sub feature only
sub_on:
	cmake -S . -B build -DSUM=OFF -DSUB=ON -DMUL=OFF -DDIV=OFF -DMOD=OFF
	cmake --build build
# this build rule disables sub feature only
sub_off:
	cmake -S . -B build -DSUM=ON -DSUB=OFF -DMUL=ON -DDIV=ON -DMOD=ON
	cmake --build build

# this build rule removes build directory to do a clean build
clean:
	rm -r build
# this build rule launches the app after building is done
launch:
	./build/Calculator

# this build rule enables sum feature only
sum_on:
	cmake -S . -B build -DSUM=ON 
	cmake --build build
# this build rule disables sum feature only
sum_off:
	cmake -S . -B build -DSUM=OFF
	cmake --build build