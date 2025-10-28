param($id)

$name = "mex"

$cpp = $name + ".cpp"
$exe = $name + ".exe"

g++-15 $cpp -o "$exe" -std=c++14

if ($?) {
    $in = $name + $id + ".in"
    $out = $name + $id + ".out"
    $ans = $name + $id + ".ans"

    (Get-Content $in) | &.\$exe > $out

    if ($?) {
        diff $out $ans
        if ($?) {
            Write-Host "AC" -ForegroundColor Green
        } else {
            Write-Host "WA on "$id -ForegroundColor Red
        }
    }
}