import json
import re
import matplotlib.pyplot as plt

data = dict()

with open('build/test_data.json') as json_file:
    raw_data = json.load(json_file)
    for i in raw_data['benchmarks']:
        if(re.findall("^\w+", i['name'])[0] in data):
            data[re.findall("^\w+", i['name'])[0]][int(re.findall("\d+$", i['name'])[0]) ] = i['cpu_time']
        else:
            data[re.findall("^\w+", i['name'])[0]] = dict()


subplot_x = []
subplot_y = []
plt.subplot(2, 1, 1)
for func_name, vals in data.items():
    for v in vals:
        if vals[v] < 20000:
            subplot_x.append(v)
            subplot_y.append(vals[v])
    plt.plot(subplot_x, subplot_y, label=func_name)
    subplot_x.clear()
    subplot_y.clear()
plt.legend()
plt.yscale('linear')
plt.ylabel('t in ns')

plt.subplot(2, 1, 2)
for func_name, val in data.items():
    plt.plot(list(val.keys()),list(val.values()), label=func_name)

plt.yscale('linear')
plt.ylabel('t in ns')
plt.suptitle('performance comparison of insert at front of container')
plt.legend()
plt.savefig("container_insert_front.png")
plt.show()
