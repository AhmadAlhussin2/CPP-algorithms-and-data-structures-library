import json
import matplotlib.pyplot as plt
import re
from collections import defaultdict
import itertools
import os

os.makedirs("charts", exist_ok=True)

category = 'sorting'

# Load the JSON file
with open(f"json_results/{category}_results.json") as f:
    benchmarks = json.load(f)

# Data structure: {data_type: {variation: {algorithm: [(input_size, time), ...]}}}
data = defaultdict(lambda: defaultdict(lambda: defaultdict(list)))

# Parse and organize benchmark entries
for entry in benchmarks['benchmarks']:
    name = entry["name"]
    time = entry["real_time"]

    # Example: "Integer Heap-Sort Random-Integer-List/16384"
    match = re.match(r"(\w+)\s+([\w\-]+)\s+([\w\-]+(?:-[\w\-]+)*)/(\d+)", name)
    if not match:
        continue

    data_type, algorithm, variation, input_size = match.groups()
    input_size = int(input_size)
    data[data_type][algorithm][variation].append((input_size, time))

# Style settings
colors = itertools.cycle(plt.get_cmap("tab10").colors)
linestyles = itertools.cycle(["-", "--", "-.", ":"])
markers = itertools.cycle(["o", "s", "D"])

# Generate plots
for data_type, algorithms in data.items():
    plt.figure(figsize=(10, 6))
    plt.title(f"{data_type} - Benchmark Results")
    plt.xlabel("Input Size")
    plt.ylabel("Real Time (ms)")

    for algorithm in algorithms:
        linestyle = next(linestyles)
        for variation, values in algorithms[algorithm].items():
            values.sort()
            x, y = zip(*values)
            plt.plot(x, y, label=f"{variation} / {algorithm}",
                     linestyle=linestyle,
                     color=next(colors),
                     marker=next(markers))

    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.savefig(f"charts/{data_type}_{category}_benchmark.png")
    plt.close()
