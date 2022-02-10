#Imports
from my_package.model import ObjectDetectionModel
from my_package.data import Dataset
from my_package.analysis import plot_boxes
from my_package.data.transforms import FlipImage, RescaleImage, BlurImage, CropImage, RotateImage
from PIL import Image
import json
from itertools import chain
import numpy as np
import matplotlib.pyplot as plt

def experiment(annotation_file, detector, transforms, outputs):
    '''
        Function to perform the desired experiments

        Arguments:
        annotation_file: Path to annotation file
        detector: The object detector
        transforms: List of transformation classes
        outputs: path of the output folder to store the images
    '''

    #Create the instance of the dataset.
    d = Dataset(annotation_file, transforms)
    #Iterate over all data items.
    for i in range(len(d)):
        image, image_dict = d[i]
    

    #Get the predictions from the detector.
        pred_boxes, pred_class, pred_score = detector(np.transpose(np.array(image), (2, 0, 1))/255)

        if len(pred_score) > 5: # top 5 confident predictions
            pred_score = pred_score[:5]
            pred_boxes = pred_boxes[:5]
            pred_class = pred_class[:5]
        
        image_dict['bboxes'] = []
        for k in range(len(pred_score)):
            my_dict = {}
            my_dict['bbox'] = list(chain.from_iterable(pred_boxes[k]))
            for j in range(len(my_dict['bbox'])):
                my_dict['bbox'][j] = int(my_dict['bbox'][j])
            my_dict['category'] = pred_class[k]
            image_dict['bboxes'].append(my_dict)

    #Draw the boxes on the image and save them.
        image = plot_boxes(location='./output/', image_dict = image_dict, image = image, saver = 1)

    #Do the required analysis experiments.
    my_image = Image.open('./data/imgs/9.jpg')
    x, y = my_image.size

    # no transformation
    d = Dataset(annotation_file, transforms = [])
    my_image, my_image_dict = d[9]
    plt.subplot(2, 4, 1)
    plt.title('Original Image')
    plt.imshow(predictor(my_image, my_image_dict, detector))

    # horizontal flipping
    d = Dataset(annotation_file, transforms = [FlipImage()])
    image, image_dict = d[9]
    plt.subplot(2, 4, 2)
    plt.title('Horizontally Flipped Image')
    plt.imshow(predictor(image, image_dict, detector))

    # blurring
    d = Dataset(annotation_file, transforms = [BlurImage(radius=3)])
    image, image_dict = d[9]
    plt.subplot(2, 4, 3)
    plt.title('Blurred Image (Radius = 3)')
    plt.imshow(predictor(image, image_dict, detector))

    # 2x rescaling
    d = Dataset(annotation_file, transforms = [RescaleImage((2*y, 2*x))])
    image, image_dict = d[9]
    plt.subplot(2, 4, 4)
    plt.title('2x Rescaled Image')
    plt.imshow(predictor(image, image_dict, detector))

    # 0.5x rescaling
    d = Dataset(annotation_file, transforms = [RescaleImage((y//2, x//2))])
    image, image_dict = d[9]
    plt.subplot(2, 4, 5)
    plt.title('0.5x Rescaled Image')
    plt.imshow(predictor(image, image_dict, detector))

    # 90 degree rotation to right
    d = Dataset(annotation_file, transforms = [RotateImage(360-90)])
    image, image_dict = d[9]
    plt.subplot(2, 4, 6)
    plt.title('90 degree Rotated Image')
    plt.imshow(predictor(image, image_dict, detector))

    # 45 degree rotation to left
    d = Dataset(annotation_file, transforms = [RotateImage(45)])
    image, image_dict = d[9]
    plt.subplot(2, 4, 7)
    plt.title('-45 degree Rotated Image')
    plt.imshow(predictor(image, image_dict, detector))

    plt.show()


def predictor(image, image_dict, detector):
    image_dict['bboxes'] = []
    pred_boxes, pred_class, pred_score = detector(np.transpose(np.array(image), (2, 0, 1))/255)
    if len(pred_score) > 5: # top 5 confident predictions
        pred_score = pred_score[:5]
        pred_boxes = pred_boxes[:5]
        pred_class = pred_class[:5]
    for k in range(len(pred_score)):
        my_dict = {}
        my_dict['bbox'] = list(chain.from_iterable(pred_boxes[k]))
        for j in range(len(my_dict['bbox'])):
            my_dict['bbox'][j] = int(my_dict['bbox'][j])
        my_dict['category'] = pred_class[k]
        image_dict['bboxes'].append(my_dict)
    return plot_boxes(image_dict = image_dict, image = image)


def main():
    detector = ObjectDetectionModel()
    experiment('./data/annotations.jsonl', detector, [], None) # Sample arguments to call experiment()


if __name__ == '__main__':
    main()