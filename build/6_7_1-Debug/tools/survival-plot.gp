#!/usr/bin/gnuplot --persist

# Set the output format and size
set term png size 900, 455
set output "./images/survivors.png"

# Set labels and title
set xlabel "Epoch"
set ylabel "Survivors"
set title "Survivors over Time"

set autoscale xy

# Set grid
set grid

# Plot the data
plot "./logs/epoch-log.txt" using 1:2 with lines lw 2 linecolor "green" title "Survivors"
