# %%
import os
import re
import sqlite3
from IPython.display import display
import pandas as pd
import numpy as np


# %%
df = pd.read_excel("LIG数据分类.xlsx", header=None)
df


# %%
vals = []
for i, s in df.iterrows():
    for i2, val in s.iteritems():
        if val is not np.nan:
            vals.append(val)


# %%
vals[:10]


# %%
for i in vals:
    if "列车管线紧急制动" in i:
        print(i)


# %%
def is_code(line: str) -> bool:
    if line.startswith("float") or line.startswith("unsigned"):
        return True
    return False


# %%
lines = []
with open("Lig_2_0.h", encoding='utf8', mode='r') as f:
    lines = f.readlines()
lines = [line.strip() for line in lines]
lines = list(filter(is_code, lines))


# %%
lines


# %%
s = set()
for i in lines:
    s.add(i.split()[0])
s


# %%
arr = []
for line in lines:
    code, comment = line.split("//", maxsplit=1)
    code = code.strip()
    if ',' in comment:
        comment = comment.split(',')[0]
    code = code.rsplit(maxsplit=1)[-1][:-1]
    arr.append([code, comment])
arr


# %%
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
arr2


# %%
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
arr3


# %%
arr3[0]

# %%
arr3[0][0]

# %%
arr3[0][1]

# %%
arr4 = []
for (index, mappings) in arr3:
    # print(index[0])
    df = pd.DataFrame(mappings)
    # display(df)
    arr4.append([index[0], df])
arr4

# %%
arr4[0][1]

# %%
arr4[0][1].iloc[0, 0]

# %%
arr4[0][1].iloc[0, 1]

# %%
len(arr4[0][1])

# %%
df1 = arr4[0][1]

# %%
df1.columns

# %%
df1[2] = ['']*len(df1)

# %%
df1

# %%
df1.columns

# %%
df1.iloc[0, 2]

# %%
arr

# %%
df1.iloc[:, 0]

# %%
arr[0]

# %%
for idx, i in enumerate(df1.iloc[:, 0].tolist()):
    found = False
    for (name, j) in arr:
        if i.replace(' ', '') in j.replace(' ', ''):
            found = True
            df1.iloc[idx, 2] = name
            break
    if not found:
        print(f"error finding {i}")


# %%
df1

# %%
len(arr)

# %%
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

# %%
# list unfound and unused things
lets_match = pd.DataFrame(unused_fields)
lets_match[2] = ['']*len(lets_match)
for i, v in enumerate(unfound_section):
    lets_match.iloc[i, 2] = v

lets_match

# %%
for section, mapping in arr4:
    print(section)
    display(mapping)


# %%

db = 'db.sqlite3'
if os.path.exists(db):
    i = 1
    while True:
        db = f'db{i}.sqlite3'
        if not os.path.exists(db):
            break
        i += 1
# %%
con = sqlite3.connect(db)

# %%
cur = con.cursor()

# %%
cur.execute('''CREATE TABLE IF NOT EXISTS val_mapping
               (section text, name text, show_name text, is_discrete bool, val int, show_val text, suffix text)''')

# %%
values = []


def get_one_row() -> pd.Series:
    for section, mapping in arr4:
        for i in range(len(mapping)):
            return mapping.iloc[i, :]


print(get_one_row().to_list())

# %%


class RowModel:
    def __init__(self) -> None:
        self.section = ''
        self.name = ''
        self.show_name = ''
        self.is_discrete = False
        self.val = 0
        self.show_val = ''
        self.suffix = ''

    def __str__(self) -> str:
        return self.__dict__()

    def __repr__(self) -> str:
        return self.__dict__()

    def tolist(self) -> list:
        return [self.section, self.name, self.show_name,
                self.is_discrete, self.val, self.show_val, self.suffix]


# %%
class Mapping:
    def __init__(self) -> None:
        self.val = ''
        self.show_val = ''
        self.suffix = ''

    def get_list(self) -> list:
        return [self.val, self.show_val, self.suffix]


# %%


def re_find(t_s):
    _arr = []
    t_s = t_s.replace('\n', ',')
    for i in range(40):
        find_mapping = f'[^0-9]{i} *=[^=]+'
        result = re.findall(find_mapping, t_s)
        if len(result) >= 1:
            s = result[0]
            if 'DB' in s:
                mybreak = 1
            s = s.replace("N/A", '')
            while s[-1].isdigit() or s[-1] == ' ':
                s = s[:-1]
            while not s[0].isdigit():
                s = s[1:]
            s = s.replace(',', ' ').strip()
            s = list(map(str.strip, s.split('=')))
            s[0] = int(s[0])
            _arr.append(s)
    return _arr


set_ = set()


def guess_val(val):
    if val == 'False' or val == '否' or 'No' in val:
        return 0
    return 1


def guess_show_val(val):
    return val


def conv(rep) -> list:
    ret = []
    l = rep.split('/')
    l = list(map(str.strip, l))
    for i in l:
        ret.append([guess_val(i), guess_show_val(i)])
    return ret


def get_val_mapping(rep) -> list:
    global set_
    set_.add(rep)
    if '/' in rep and not 'N/A' in rep:
        return conv(rep)
    return re_find(rep)


# %%
def get_representation(rep) -> list:
    mapping_all = []
    if rep is np.nan:
        mapping_all.append(Mapping().get_list())
        return mapping_all
    else:
        if '0 =' in rep or ('/' in rep and not 'xxx' in rep):
            val_mapping = get_val_mapping(rep)
            for m in val_mapping:
                map_ = Mapping()
                map_.val = m[0]
                map_.show_val = m[1]
                map_.suffix = ''
                mapping_all.append(map_.get_list())
            return mapping_all
        else:
            suffix = rep.strip().split()[-1]
            map_ = Mapping()
            map_.suffix = suffix
            mapping_all.append(map_.get_list())
            return mapping_all


# %%
def get_rows():
    row_models = []
    for section, mapping in arr4:
        for i in range(len(mapping)):
            list_ = mapping.iloc[i, :].to_list()
            show_name, format_, name = list_
            if name in ['ThrottleNotch', 'LocomotiveOperatingMode']:
                my_break = 1
            repr_ = get_representation(format_)
            is_discrete = False
            val, show_val, suffix = repr_[0]
            if suffix == '':
                is_discrete = True
            for val, show_val, suffix in repr_:
                row_model = RowModel()
                row_model.section = section
                row_model.show_name = show_name
                row_model.name = name
                row_model.is_discrete = is_discrete
                row_model.val = val
                row_model.show_val = show_val
                row_model.suffix = suffix
                row_models.append(row_model.tolist())
    return row_models


# %%
values = get_rows()
values

# %% [markdown]
#

# %%
set_

# %%


def format_rep():
    global set_
    arr = []
    for s in set_:
        arr.append(s.replace('\n', ','))
    return arr


format_rep()

# %%
cur.executemany(
    'insert into val_mapping (section, name, show_name, is_discrete, val, show_val, suffix) values'
    ' (?, ?, ?, ?, ?, ?, ?)',
    values
)

# %%
con.commit()
con.close()

# %%

# %%


def test_find():
    t_s = '0 =重置 ,1 = Ready NP ,2 = Crank,3 = Crank Clean Up ,4 = Jog Set Up,5 = Jog,6 = Jog Clean Up ,7 = Ready P Set,8 = Ready P,9 = Ready P Clean ,10 = Motor Set Up ,11 = Motor,12 = Motor Clean ,13 = Brake Set Up Config,14 = Brake Set Up ,15 = Brake Set Up Clean Up,16 = Brake Config,17 = Brake,18 = Brake Clean Up ,19 = Self Test Set Up ,20 = Self Test,21 = Pre Lube Self Test,22 = Pre Lube Self Test Clean Up,23 = Self Test Clean Up,24 = Self Load Set Up ,25 = Self Load,26 = Self Load Clean Up,27 = MMM error,28 = MMM done,32 = Other, N/A'
    for i in range(40):
        find_mapping = f'[^0-9]{i} *=[^=]+'
        result = re.findall(find_mapping, t_s)
        if len(result) >= 1:
            s = result[0]
            while s[-1].isdigit() or s[-1] == ',' or s[-1] == ' ':
                s = s[:-1]
            if s[0] == ',':
                s = s[1:]
            s = s.strip()
            if s[-3:] == "N/A":
                s = s[:-3]
            while s[-1].isdigit() or s[-1] == ',' or s[-1] == ' ':
                s = s[:-1]
            s = list(map(str.strip, s.split('=')))
            print(s)


test_find()


# %%
