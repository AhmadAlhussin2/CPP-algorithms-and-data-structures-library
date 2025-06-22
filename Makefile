build-sorting-algorithms:
	bazel build //src/sorting_algorithms -c opt

run-sorting-algorithms:
	./bazel-bin/src/sorting_algorithms/sorting_algorithms --benchmark_out=./json_results/sorting_results.json --benchmark_out_format=json

visualize-sorting-algorithms:
	python3 visualization/visualize.py sorting_results


build-ordered-containers-algorithms:
	bazel build //src/ordered_containers -c opt

run-ordered-containers:
	./bazel-bin/src/ordered_containers/ordered_containers --benchmark_out=./json_results/ordered_containers_results.json --benchmark_out_format=json

visualize-ordered-containers:
	python3 visualization/visualize.py ordered_containers_results