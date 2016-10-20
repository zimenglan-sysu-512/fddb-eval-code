#!/usr/bin/env sh

# Usage for the evaluation binary:
# ------------------------------

# ./evaluate [OPTIONS]
#    -h              : print usage
#    -a fileName     : file with face annotations (default: ellipseList.txt)
#    -d fileName     : file with detections (default: faceList.txt)
#    -f format       : representation of faces in the detection file (default: 0)
#                      [ 0 (rectangle), 1 (ellipse), or  2 (pixels) ]
#    -i dirName      : directory where the original images are stored
# 		     (default: ~/scratch/Data/facesInTheWild/)
#    -l fileName     : file with list of images to be evaluated (default: temp.txt)
#    -r fileName     : prefix for files to store the ROC curves (default: temp)
#    -s              : display the matching detection-annotation pairs.
#    -z imageFormat  : image format used for reading images for the annotation set
#                      (default: .jpg )

# exper_name=wider-face-600-1000-end2end-all-rs_conv5_ohem
# exper_name=wider-face-600-1000-end2end-all-rs_conv5
# exper_name=wider-face-600-1000-resnet50-rfcn
# exper_name=wider-face-600-1000-resnet50-rfcn-v2
# exper_name=resnet-101L_res3a
# exper_name=resnet-101L_res3a_ohem
# exper_name=resnet-101L_res3a_ohem_ms
# exper_name=example_384_original_plateau
exper_name=example_384_original_plateau_ohem2person_rs_convf_8x

a_fileName="../FDDB-folds/ellipse-files/all_folds_ellipseList.label"
# d_fileName="../res_dets/${exper_name}/all_folds_pred_0.15_0.85.label"
# d_fileName="../res_dets/${exper_name}/all_folds_pred_0.15_0.85_sepe_600_864.label"
d_fileName="../res_dets/${exper_name}/all_folds_pred_0.15_0.85.label"
format=0
dirName="../originalPics/"
l_fileName="../FDDB-folds/ims-files/all_folds.label"
r_fileName="../res_dets/${exper_name}/all_folds_pred_0.15_0.85_roc_curves"
imageFormat=".jpg"

./evaluate -a $a_fileName -d $d_fileName -f $format -i $dirName -l $l_fileName -r $r_fileName -z $imageFormat

# ./evaluate -a $a_fileName -d $d_fileName -f $format -i $dirName -l $l_fileName -r $r_fileName -s -z $imageFormat
