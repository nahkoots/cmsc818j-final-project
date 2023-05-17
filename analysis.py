import hatchet as ht
import numpy as np
import pandas as pd

# replace with your database folders
dirs = ["hpctoolkit-bitalign-database-2561827", "hpctoolkit-bitalign-database-2561827"]
dfs = [0, 0]

for (i, dir) in zip(range(len(dirs)), dirs):
	graph = ht.GraphFrame.from_hpctoolkit(dir)
	graph.drop_index_levels(function=np.max)
	filtered = graph.filter(lambda x: x['time'] > .01)

	grouped = graph.dataframe.groupby('name').sum()
	dfs[i] = grouped
	
	sorted_df = grouped.sort_values(by=['time'], ascending=False)
	print(pd.DataFrame(sorted_df, columns=['time (inc)', 'time']).head(20))

	with open("graph" + str(i) + ".dot", "w") as dot_file:
		dot_file.write(filtered.to_dot())
	
	squashed = filtered.squash()
	print(squashed.tree())
		
print("big minus small")
diff = dfs[1] / dfs[0]
sorted_df = diff.sort_values(by=['time (inc)'], ascending=False)
print(pd.DataFrame(sorted_df, columns=['time (inc)', 'time']).head(40))

for df in dfs:
	print(df.filter(regex='^main$', axis=0).head(1))
