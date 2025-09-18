import fastify, { type FastifyReply, type FastifyRequest } from 'fastify'
import cors from '@fastify/cors'

const Fastify = fastify({logger:true});
const PORT = 5000

//route -> method, path, handler

Fastify.get('/', async ( req: FastifyRequest, reply: FastifyReply) => {
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
