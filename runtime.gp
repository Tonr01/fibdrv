set title "Fibonacci runtime"
set xlabel "F(n)"
set ylabel "time (ns)"
set terminal png font " Verdana, 10 "
set output 'runtime_result.png'
set key left

plot \
"runtime_data" using 1:2 with linespoints linewidth 2 title "DP", \
"runtime_data" using 1:3 with linespoints linewidth 2 title "Fast Doubling" \
