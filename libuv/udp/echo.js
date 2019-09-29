// tcp-echo-svr.js
const net = require('net')
net.createServer((c) => c.pipe(c)).listen(12306)
