param($id)

$name = "mst"

$cpp = $name + ".cpp"
$exe = $name + ".exe"

g++-15 $cpp -o "$exe" -std=c++14

Write-Host "Compile finsihed"

if ($?) {
    $in = ".\" + $name + $id + ".in"
    $out = ".\" + $name + $id + ".out"
    $ans = ".\" + $name + $id + ".ans"

    (Get-Content $in) | &.\$exe > $out

    if ($?) {
        if ((Get-Content $out) -ne (Get-Content $ans)) {
            Write-Host "WA on "$id -ForegroundColor Red
        } else {
            Write-Host "AC" -ForegroundColor Green
        }
    }
}