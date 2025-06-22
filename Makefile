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


build-bipartite-matching:
	bazel build //src/bipartite_matching -c opt

run-bipartite_matching:
	./bazel-bin/src/bipartite_matching/bipartite_matching --benchmark_out=./json_results/bipartite_matching_results.json --benchmark_out_format=json


visualize-bipartite-matching:
	python3 visualization/visualize.py bipartite_matching_results