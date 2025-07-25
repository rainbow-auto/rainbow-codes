g++-15 $1.cpp -std=c++14 -o $1 || exit
cnt=1
while cnt<=$2 do
    ./$1 < ex_$1cnt.in > ex_$1cnt.out || exit
    echo "test $cnt passed"
done