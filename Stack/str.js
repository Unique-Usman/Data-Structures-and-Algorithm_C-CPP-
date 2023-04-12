s1 = "Usman***@438(*****"
s1 = s1.split("").map(s => return (s == "*" ? "" : s))
console.log(s1)
