#!/bin/python3

import matplotlib.pyplot as plt
import numpy as np
import os


class GroupedPoint:
    def __init__(self, items, names, bins, ms) -> None:
        self.items = items
        self.names = names
        self.bins = bins
        self.ms = ms

    def get_info_at(self, index):
        return (self.names[index], self.bins[index], self.ms[index])


# Read a file and return a list of GroupedPoint
def read_file(filename):
    with open(filename, 'r') as f:
        lines = f.readlines()
        grouped_points = []
        # Every six lines form a GroupedPoint,
        # the first line is a single number representing `items`,
        # the rest five lines are three segments separated by `#`,
        # representing names, `number_of_bins` and `time_in_ms` respectively.
        # Their formats are like:
        #   name#number_of_bins#time_in_ms
        for i in range(0, len(lines), 6):
            items = int(lines[i].strip())
            names = []
            bins = []
            ms = []
            for j in range(1, 6):
                name, number_of_bins, time_in_ms = lines[i + j].split('#')
                names.append(name)
                bins.append(int(number_of_bins))
                ms.append(int(time_in_ms))
            grouped_points.append(GroupedPoint(items, names, bins, ms))
        return grouped_points


if __name__ == "__main__":
    # Get all file named "*.txt" under `build/`(non-recursive, name-only)
    files = os.popen(
        "find build/ -maxdepth 1 -name '*.txt' -printf '%f\n'").read().splitlines()

    grouped_points = read_file("build/"+files[3])
    num_items = tuple(
        grouped_points[i].items for i in range(len(grouped_points)))
    allocator_names = grouped_points[0].names
    # This is a list of tuple of bins, each tuple is a allocator's bins for every number_of_items
    # For example, allocator_bins[0] is a tuple (grouped_points[i].bins[0], for i in range(len(grouped_points))
    allocator_bins = []
    # This is a list of tuple of ms, each tuple is a allocator's ms for every number_of_items
    allocator_ms = []
    for i in range(len(allocator_names)):
        allocator_bins.append(tuple(
            grouped_points[j].bins[i] for j in range(len(grouped_points))))
        allocator_ms.append(tuple(
            grouped_points[j].ms[i] for j in range(len(grouped_points))))
    # zip the name with bins and ms
    name2bins = dict(zip(allocator_names, allocator_bins))
    name2ms = dict(zip(allocator_names, allocator_ms))

    # Plot the grouped bar chart
    x = np.arange(len(num_items))  # the label locations
    width = 0.15  # the width of the bars
    multiplier = 0
    fig, ax = plt.subplots(layout='constrained')
    for name, bins in name2bins.items():
        offset = width * multiplier
        rects = ax.bar(x + offset, bins, width, label=name)
        ax.bar_label(rects, padding=3)
        multiplier += 1

    # Add some text for labels, title and custom x-axis tick labels, etc.
    ax.set_ylabel('Number of bins')
    ax.set_title('Number of bins by number of items')
    ax.set_xticks(x + width, num_items)
    ax.legend(loc='upper left', ncol=3)
    ax.set_ylim(0, 1000)

    plt.savefig('build/plot.png')
    exit(0)

    penguin_means = {
        'Bill Depth': (18.35, 18.43, 14.98),
        'Bill Length': (38.79, 48.83, 47.50),
        'Flipper Length': (189.95, 195.82, 217.19),
    }

    x = np.arange(len(species))  # the label locations
    width = 0.25  # the width of the bars
    multiplier = 0

    fig, ax = plt.subplots(layout='constrained')

    for attribute, measurement in penguin_means.items():
        offset = width * multiplier
        rects = ax.bar(x + offset, measurement, width, label=attribute)
        ax.bar_label(rects, padding=3)
        multiplier += 1

    # Add some text for labels, title and custom x-axis tick labels, etc.
    ax.set_ylabel('Length (mm)')
    ax.set_title('Penguin attributes by species')
    ax.set_xticks(x + width, species)
    ax.legend(loc='upper left', ncols=3)
    ax.set_ylim(0, 250)

    plt.savefig('build/plot.png')
