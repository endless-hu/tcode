#!/bin/python3

import matplotlib.pyplot as plt
import numpy as np
import os


class GroupedPoint:
    def __init__(self, items, names, bins, ms, opt) -> None:
        self.items = items
        self.names = names
        self.bins = bins
        self.ms = ms
        self.opt = opt

    def get_info_at(self, index):
        return (self.names[index], self.bins[index], self.ms[index])


# Read a file and
# return (a list of GroupedPoint, max number of bins, max time in ms)
def read_file(filename):
    with open(filename, 'r') as f:
        lines = f.readlines()
        max_bins = 0
        max_ms = 0
        grouped_points = []
        # Every six lines form a GroupedPoint,
        # the first line is a single number representing `items`.
        # However, there could be two numbers seperated by a blank, which means
        # the first number is `items` and the second number is `opt`.
        # the rest five lines are three segments separated by `#`,
        # representing names, `number_of_bins` and `time_in_ms` respectively.
        # Their formats are like:
        #   name#number_of_bins#time_in_ms
        for i in range(0, len(lines), 6):
            items = int(lines[i].split()[0])
            if len(lines[i].split()) > 1:
                opts = int(lines[i].split()[1])
            else:
                opts = None
            names = []
            bins = []
            ms = []
            for j in range(1, 6):
                name, number_of_bins, time_in_ms = lines[i + j].split('#')
                if int(number_of_bins) > max_bins:
                    max_bins = int(number_of_bins)
                if int(time_in_ms) > max_ms:
                    max_ms = int(time_in_ms)
                names.append(name)
                bins.append(int(number_of_bins))
                ms.append(int(time_in_ms))
            grouped_points.append(GroupedPoint(items, names, bins, ms, opts))
        return (grouped_points, max_bins, max_ms)


def plot(filename):
    grouped_points, max_bins, max_ms = read_file("build/"+filename)
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
    if grouped_points[0].opt is not None:
        name2bins['opt'] = tuple(grouped_points[i].opt for i in range(len(grouped_points)))
    name2ms = dict(zip(allocator_names, allocator_ms))

    # Plot the grouped bar chart
    x = np.arange(len(num_items))  # the label locations
    width = 0.15  # the width of the bars

    multiplier = 0
    fig, ax = plt.subplots(layout='constrained')
    fig.set_size_inches(10, 5)
    for name, bins in name2bins.items():
        offset = width * multiplier
        rects = ax.bar(x + offset, bins, width, label=name)
        ax.bar_label(rects, padding=5, fontsize=6)
        multiplier += 1

    # Add some text for labels, title and custom x-axis tick labels, etc.
    ax.set_ylabel('Number of bins')
    ax.set_title('Number of bins by number of items')
    ax.set_xticks(x + width, num_items)
    ax.legend(loc='upper left', ncol=3)
    # y_lim = max_bins / 0.8, then round up to the nearest 100
    ax.set_ylim(0, int(max_bins / 0.8 / 100 + 1) * 100)

    plt.savefig(f'build/{filename}-bin.png')

    multiplier = 0
    fig, ax = plt.subplots(layout='constrained')
    fig.set_size_inches(10, 5)
    for name, ms in name2ms.items():
        offset = width * multiplier
        rects = ax.bar(x + offset, ms, width, label=name)
        ax.bar_label(rects, padding=5, fontsize=6)
        multiplier += 1

    # Add some text for labels, title and custom x-axis tick labels, etc.
    ax.set_ylabel('Time (ms)')
    ax.set_title('Time used by number of items')
    ax.set_xticks(x + width, num_items)
    ax.legend(loc='upper left', ncol=3)
    # y_lim = max_ms / 0.8, then round up to the nearest 10
    ax.set_ylim(0, int(max_ms / 0.8 / 10 + 1) * 10)

    plt.savefig(f'build/{filename}-time.png')


if __name__ == "__main__":
    # Get all file named "*.txt" under `build/`(non-recursive, name-only)
    files = os.popen(
        "find build/ -maxdepth 1 -name '*.txt' -printf '%f\n'").read().splitlines()

    for file in files:
        print(f"Plotting {file}")
        plot(file)
