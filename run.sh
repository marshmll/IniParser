if [ ! -d "build/" ]
then
    mkdir build
    cd build
    cmake ..
    cd ..
fi

cp src/file.ini build/bin/file.ini

cd build
make
cd bin
./IniParser
cd ../../