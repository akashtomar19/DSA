strs = ["mkdir /usr/home", "mkdir /usr/home/foldera"]
st = set()
for s in strs:
    p = s.split()
    p = p[1:]
    st.add(p[0])

print(len(st))

   # st.add(j for j in p[0].split('/')) #not allowed generator expression


    