#! /usr/bin/gnuplot

# Compare your continue ROC curves with other methods
# At terminal: gnuplot contROC2.p
set terminal png size 960, 720 enhanced font 'Verdana,9'
set key font ",12"
set size 1,1
set xtics 250
set ytics 0.1
set grid
set ylabel "True positive rate"
set xlabel "False positive (cont)"
set xr [0:1000]
set yr [0:1.0]

# Compare your continue ROC curves with other methods
# At terminal: gnuplot contROC2.p

set key below
set output "contROC-compare2.png"

# ddk = "../res_dets/wider-face-600-1000-end2end-all-rs_conv5/all_folds_pred_0.15_0.85_roc_curvesContROC.txt"
# ddk = "../res_dets/wider-face-600-1000-end2end-all-rs_conv5_ohem/all_folds_pred_0.15_0.85_roc_curvesContROC.txt"
ddk = "../res_dets/wider-face-600-1000-end2end-all-rs_conv5/all_folds_pred_0.15_0.85_sepe_600_864_roc_curvesContROC.txt"

plot  \
			ddk using 2:1 title 'ddk.' with lines lw 2, \
			"rocCurves/DDFD_ContROC.txt" 				 using 2:1 title 'DDFD' with lines lw 2 , \
			"rocCurves/frcnContROC.txt" 				 using 2:1 title 'frcnn' with lines lw 2, \
			"rocCurves/UnitBox-ContROC.txt" 		 using 2:1 title 'unitbox' with lines lw 2, \
			"rocCurves/CasCNN-ContROC.txt"       using 2:1 title 'CascadeCNN' with lines lw 2, \
			"rocCurves/cvit_ContROC.txt"         using 2:1 title 'Vijay et al.' with lines lw 2, \
			"rocCurves/MTCNN-ContROC.txt"        using 2:1 title 'Zhang et al' with lines lw 2, \
			"rocCurves/Hyperface_ContROC.txt"    using 2:1 title 'Hyperface' with lines lw 2, \
			"rocCurves/resnet50-hnm-ContROC.txt" using 2:1 title 'Xiaomi' with lines lw 2