import type { FastifyHttpOptions, FastifyInstance, FastifyServerOptions } from "fastify"

async function routes (fastify: FastifyInstance, options: FastifyServerOptions) {

    fastify.get('/', async (request , reply) => {
        reply.code(200).header('Content-Type', 'application/json; charset=utf-8')
    return { hello: 'Hello world!' }
  })

    fastify.get('/users', async (request , reply) => {
        reply.code(200).header('Content-Type', 'application/json; charset=utf-8')
    return { hello: 'Users' }
  })
}

export default routes;