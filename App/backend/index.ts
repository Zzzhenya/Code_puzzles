import fastify from 'fastify'
import cors from '@fastify/cors'

// const Fastify = require('fastify')(
// 	{ logger: true })
// import { FastifyInstance, FastifyReply, FastifyRequest } from 'fastify';

// const cors = require('@fastify/cors')();
// import cors from '@fastify/cors'

const Fastify = fastify({logger:true});
const PORT = 5000

//route -> methd, path, handler

Fastify.get('/', (req, reply) => {
  reply
    .code(200)
    .header('Content-Type', 'application/json; charset=utf-8')
    .send({ 'hello': 'Hello World!' })
	// reply.send({ greeting: 'Hello!' })
})

function listening(){
    console.log(`App server is up and running on localhost: port 5000`);
};

const start = async () => { 
	try {
    // await Fastify.register(cors, {  });
    console.log('here\n');
		await Fastify.listen({port:PORT})
	}
	catch (error) {
		Fastify.log.error(error)
		process.exit(1)
	}

}

const setupcors = async () => {
  await Fastify.register(cors, {  });
  console.log('here\n');
}

setupcors();
Fastify.log.info('Something important happened!');
start();
/*
console.log("hello world");
console.log("hello hello");

import cors from '@fastify/cors'


import fastify from 'fastify'
// import FastifyInstance = require('fastify');

const app = fastify(
    { logger:true}
);

app.get('/', async (request, reply) => {
    await app.register(cors, {  });
    reply.send({hello:'world'});
})

app.listen({port:3000}, (err, address)=> {
  if (err) {
    app.log.error(err);
    process.exit(1);
  }
  app.log.info(`Server listening at ${address}`);
}
);

// server.get('/ping', async (request, reply) => {
//   return 'pong\n'
// })

// server.listen({ port: 8080 }, (err, address) => {
//   if (err) {
//     console.error(err)
//     process.exit(1)
//   }
//   console.log(`Server listening at ${address}`)
// })*/
