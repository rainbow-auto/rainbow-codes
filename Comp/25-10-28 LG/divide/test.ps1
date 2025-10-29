param($id)

$name = "divide"

$cpp = $name + ".cpp"
$bin = $name

g++-15 $cpp -o $bin -std=c++14

if (($?)) {
    Write-Host "Complie Finished"
    
    $in = $name + $id + ".in"
    $out = $name + $id + ".out"
    $ans = $name + $id + ".ans"

    $bin = ".\" + $bin;

    (Get-Content $in) | &$bin > $out

    diff --strip-trailing-cr ($out) ($ans)

    if (($?)) {
        Write-Host "AC" -ForegroundColor Green
    } else {
        Write-Host "WA" -ForegroundColor Red
    }
}