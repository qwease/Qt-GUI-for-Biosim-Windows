#!/usr/bin/gnuplot --persist

# Set the output format and size
set term png size 900, 455
set output "./images/diversity.png"

# Set labels, title, and axis
set xlabel "Epoch"
set ylabel "Scaled Diversity"
set title "Diversity over Time"

set autoscale xy

# Set grid
set grid

# Plot the data
plot "./logs/epoch-log.txt" using 1:3 with lines lw 2 linecolor "purple" title "Diversity"

