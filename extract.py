# %%
import sqlite3
import pandas as pd
import numpy as np

# %%
# read code


def is_code(line: str) -> bool:
    if line.startswith("float") or line.startswith("unsigned"):
        return True
    return False


lines = []
with open("Lig_2_0.h", encoding='utf8', mode='r') as f:
    lines = f.readlines()
lines = [line.strip() for line in lines]
lines = list(filter(is_code, lines))


# %%
# split code and comments
arr = []
for line in lines:
    code, comment = line.split("//", maxsplit=1)
    code = code.strip()
    if ',' in comment:
        comment = comment.split(',')[0]
    code = code.rsplit(maxsplit=1)[-1][:-1]
    arr.append([code, comment])


# %%

# Read Excel
df = pd.read_excel("LIG数据分类.xlsx", header=None)

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

# %%
# matching

errata = {
    "TAP 电流": "TAC电流",
    "引擎控制开关（运行）": "引擎控制开关 运行",
    "引擎控制开关（发动）": "引擎控制开关启动",
    '引擎控制开关（移车）': '引擎控制开关慢速',
    '移车按钮': '慢速按钮',
    '0x1013 电空制动设置': '电控制动设置$',
    '0x100F 电空制动设置模式': '电控制动设置模式',
    '辅助发电机励磁切除': '辅助发电机现场切除',
    'R侧増压器转速': '右侧増压器转速',
    "列车管线 27 慢速": "列车管线27 慢速TL27",
    "电阻制动百份比": " 电阻制动百份比%",
    "车管线 12 档位 B 状态": "列车管线12 档位B状态",
    "车管线 15 档位 A 状态": "列车管线15 档位A状态"
}

found_fields = []
unfound_section = []
arr5 = arr4.copy()
for section, mapping in arr5:
    mapping[2] = ['']*len(mapping)
    for idx, i in enumerate(mapping.iloc[:, 0].tolist()):
        found = False
        for (name, j) in arr:
            for m in errata.keys():
                if m in j:
                    j = j.replace(m, errata[m])
            if i == '电空制动设置':
                i = '电控制动设置$'
            if i.replace(' ', '').strip() in j.replace(' ', '').strip():
                found = True
                found_fields.append(name)
                mapping.iloc[idx, 2] = name
                break
        if not found:
            print(f"error finding {section}.{i}")
            unfound_section.append(i)


unused_fields = list(filter(lambda x: x[0] not in found_fields, arr))


# %%
# testing
for (name, j) in arr:
    for m in errata.keys():
        if m in j:
            print(f"matched: {j}")
            j = j.replace(m, errata[m])
            print(f"replace to: {j}")

# %%
# list unfound and unused things
lets_match = pd.DataFrame(unused_fields)
lets_match[2] = ['']*len(lets_match)
for i, v in enumerate(unfound_section):
    lets_match.iloc[i, 2] = v

lets_match


# %%
df_all = []
for section, mapping in arr4:
    df_all.append(mapping)


# %%


con = sqlite3.connect(":memory:")
cur = con.cursor()

# %%
arr5

# %%
