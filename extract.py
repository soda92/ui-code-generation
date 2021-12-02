# %%
import pandas as pd
import numpy as np


df = pd.read_excel("LIG数据分类.xlsx", header=None)


vals = []
for i, s in df.iterrows():
    for i2, val in s.iteritems():
        if val is not np.nan:
            vals.append(val)


def is_code(line: str) -> bool:
    if line.startswith("float") or line.startswith("unsigned"):
        return True
    return False


lines = []
with open("Lig_2_0.h", encoding='utf8', mode='r') as f:
    lines = f.readlines()
lines = [line.strip() for line in lines]
lines = list(filter(is_code, lines))

arr = []
for line in lines:
    code, comment = line.split("//", maxsplit=1)
    code = code.strip()
    if ',' in comment:
        comment = comment.split(',')[0]
    code = code.rsplit(maxsplit=1)[-1][:-1]
    arr.append([code, comment])


arr2 = []
for i, row in df.iterrows():
    if len(row.dropna()) == 1:
        name = row.dropna()[0]
        arr2.append([name])
    else:
        if len(row) % 2 == 0:
            for i in range(len(row)):
                if i % 2 == 1:
                    pass
                else:
                    if not (row[i] is np.nan):
                        arr2.append([row[i], row[i+1]])


arr3 = []
for i, val in enumerate(arr2):
    if len(val) == 1:
        l = []
        j = i+1
        if i+1 == len(arr2):
            arr3.append([val, l])
            break
        else:
            while len(arr2[j]) != 1:
                l.append(arr2[j])
                j += 1
        arr3.append([val, l])

arr4 = []
for (index, mappings) in arr3:
    # print(index[0])
    df = pd.DataFrame(mappings)
    # display(df)
    arr4.append([index[0], df])



found_fields = []
unfound_section = []
for section, mapping in arr4:
    mapping[2] = ['']*len(mapping)
    for idx, i in enumerate(mapping.iloc[:, 0].tolist()):
        found = False
        for (name, j) in arr:
            if i.replace(' ', '') in j.replace(' ', ''):
                found = True
                found_fields.append(name)
                mapping.iloc[idx, 2] = name
                break
        if not found:
            print(f"error finding {section}.{i}")
            unfound_section.append(i)


unused_fields = list(filter(lambda x: x[0] not in found_fields, arr))

lets_match = pd.DataFrame(unused_fields)
lets_match[2] = ['']*len(lets_match)
for i,v in enumerate(unfound_section):
    lets_match.iloc[i,2] = v

# %%
lets_match


# %%
df_all = []
for section,mapping in arr4:
    df_all.append(mapping)

errata = {
    "TAP 电流": "TAC电流",
    "引擎控制开关（运行）": "引擎控制开关 运行",
    "引擎控制开关（发动）": "引擎控制开关启动",
    "列车管线 27 慢速": "列车管线27 慢速TL27",
    "电阻制动百份比": " 电阻制动百份比%",
    "车管线 12 档位 B 状态": "列车管线12 档位B状态",
    "车管线 15 档位 A 状态":"列车管线15 档位A状态"
}

errata

# %%
import sqlite3

con = sqlite3.connect(":memory:")
cur = con.cursor()




