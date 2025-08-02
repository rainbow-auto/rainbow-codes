
for i in {1..100}; do 
    ./gen
    ./music
    ./music0
    diff music.out music0.out
    echo "$i passed"
done