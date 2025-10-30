param($id)

$name = "sort"

g++-15 ($name + ".cpp") -o $name -std=c++14 -O2

if (($?)) {
    (Get-Content (".\" + $id + ".in")) | &(".\" + $name) > (".\" + $id + ".out")
    diff (".\" + $id + ".out") (".\" + $id + ".ans")

    if (($?)) {
        Write-Host "AC" -ForegroundColor Green
    } else {
        Write-Host "WA" -ForegroundColor Red
    }
}