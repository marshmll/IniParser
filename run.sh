if [ ! -d "build/" ]
then
    mkdir build
    cd build
    cmake -DCMAKE_BUILD_TYPE=Debug ..
    cd ..
fi

cp src/file.ini build/bin/file.ini

cd build
make
cd bin
./IniParser
cd ../../