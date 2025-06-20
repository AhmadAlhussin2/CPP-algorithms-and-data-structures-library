build-sorting-algorithms:
	bazel build //src -c opt

run-sorting-algorithms:
	./bazel-bin/src/sorting_algorithms/sorting_algorithms --benchmark_out=./json_results/sorting_results.json --benchmark_out_format=json

visualize-sorting-algorithms:
	python3 visualization/visualize.py