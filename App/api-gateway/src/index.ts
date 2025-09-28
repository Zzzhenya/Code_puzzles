// main gateway app
/*
Create the Fastify Server (API Gateway Entry Point)
Goal: Create the central HTTP server that handles all incoming traffic.
Fastify Features: fastify(), .listen()
Tasks:
  Initialize a Fastify instance.
  Set logging and error handling options.
  Start listening on a specified port.
*/
import fastify, { type FastifyReply, type FastifyRequest } from 'fastify'
import cors from '@fastify/cors'
import firstRoute from './routes.js'
// console.log(services.users);

const Fastify = fastify({logger:true});

const PORT = 5000
// const PORT = services.port;
// const PORT = 5000
// const JWT_SECRET='supersecretkey'

//route -> method, path, handler

// Fastify.register(firstRoute)

// Fastify.get('/', async ( req: FastifyRequest, reply: FastifyReply) => {
//   reply
//     .code(200)
//     .header('Content-Type', 'application/json; charset=utf-8')
//     .send({ 'hello': 'Hello World!' })
// 	// reply.send({ greeting: 'Hello!' })
// })

function listening(){
    console.log(`App server is up and running on localhost: port 5000`);
};

const start = async () => { 
	try {
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
console.log("port: " + PORT);
Fastify.register(firstRoute)
Fastify.log.info('Something important happened!');
start();