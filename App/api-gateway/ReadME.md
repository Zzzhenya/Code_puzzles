API gateway
* entry point to all external requests
* handles : 
    routing : Forward requests to correct microservice
    authentication: Validate JWT tokens or session
    rate limiting: Prevent abuse
    logging: Log incoming requests and responses
    request transformation: Modify headers, paths, or body
    response handling: Format or sanitize responses
* Proxies or forwards requests to your internal microservices (users, orders, products, etc.)

1. Initialize the Project with TypeScript

Goal: Set up a robust TypeScript-based Fastify project.
Fastify Features: None yet — just a clean setup.
Tasks:
    Set up TypeScript compiler configuration.
    Install Fastify with type support.
    Configure project structure for scalability (routes, plugins, services, etc.).

2. Create the Fastify Server (API Gateway Entry Point)

Goal: Create the central HTTP server that handles all incoming traffic.
Fastify Features: fastify(), .listen()
Tasks:
    Initialize a Fastify instance.
    Set logging and error handling options.     
    Start listening on a specified port.

3. Set Up Route Forwarding to Microservices

Goal: Receive client requests and forward them to appropriate backend microservices.
Fastify Features: register(), route declarations (GET, POST, etc.)
Tasks:
    Create route handlers that match your microservices (e.g., /users, /orders).
    Within those handlers, forward the request to the appropriate service via HTTP or message broker.

4. Encapsulate and Register Routes as Plugins

Goal: Keep the route logic modular and composable.
Fastify Features: register(), plugin encapsulation
Tasks:
    Use Fastify’s plugin system to encapsulate route modules.
    Register these modules with route prefixes for clean APIs (e.g., /api/users).

5. Handle Inter-Service Communication

Goal: Communicate with other microservices effectively.
Fastify Features: While Fastify doesn't handle this directly, you can use libraries (undici, axios) inside handlers.
Tasks:
    Send and receive HTTP requests to/from downstream services.
    Add retry logic or fallback mechanisms if necessary.

6. Implement Authentication & Authorization

Goal: Secure access to internal microservices.
Fastify Features: Hooks (onRequest, preHandler), fastify-jwt, fastify-auth
Tasks:
    Validate JWTs or API keys on incoming requests.
    Use hooks to centralize auth logic across routes.
    Optionally forward auth headers to backend services.

7. Add Validation and Serialization

Goal: Ensure data integrity and improve performance.
Fastify Features: Schema validation, response serialization
Tasks:
    Define JSON Schemas for request bodies, params, and responses.
    Use Fastify's built-in validation and serialization to enforce types and improve speed.

8. Apply Global Error Handling and Logging

Goal: Ensure reliability and observability.
Fastify Features: setErrorHandler(), onError hooks, built-in logger
Tasks:
    Log all errors and requests.
    Customize global error responses for consistency.
    Integrate with external logging or monitoring tools if needed (e.g., Prometheus, Datadog).

9. Enable CORS, Rate Limiting, and Security Headers

Goal: Protect the gateway from misuse and ensure browser compatibility.
Fastify Features: Plugins like fastify-cors, fastify-rate-limit, fastify-helmet
Tasks:
    Set up CORS policies.
    Add rate limiting to prevent abuse.
    Include security headers for common threats.

10. Prepare for Scalability and Deployment

Goal: Get the API Gateway production-ready.
Fastify Features: Lightweight and high-performance core, plugin ecosystem
Tasks:
    Containerize with Docker.
    Use Fastify’s low overhead to scale efficiently.
    Configure environment variables and service discovery (if needed).

11. Add Health Checks and Metrics

Goal: Monitor the health of the gateway.
Fastify Features: fastify-healthcheck, fastify-metrics
Tasks:
    Expose a /health endpoint.
    Integrate metrics collection for monitoring latency, error rates, etc.

Summary Table
Step	Purpose	Fastify Feature
1	Initialize Project	—
2	Start Server	fastify(), .listen()
3	Route Requests	register(), route methods
4	Modularize	Plugin encapsulation
5	Communicate with Services	Use inside route handlers
6	Authenticate Requests	onRequest, preHandler, fastify-jwt
7	Validate Data	JSON Schema, serialization
8	Error Handling & Logging	setErrorHandler(), logging hooks
9	Secure Gateway	fastify-cors, fastify-rate-limit, fastify-helmet
10	Deploy & Scale	Lightweight core, plugin flexibility
11	Health & Metrics	fastify-healthcheck, fastify-metrics


// installing "fastify-http-proxy": "^6.2.2",
undici  <=5.28.5
Severity: high
undici before v5.8.0 vulnerable to CRLF injection in request headers - https://github.com/advisories/GHSA-3cvr-822r-rqcc
ProxyAgent vulnerable to MITM - https://github.com/advisories/GHSA-pgw7-wx7w-2w33
undici before v5.8.0 vulnerable to uncleared cookies on cross-host / cross-origin redirect - https://github.com/advisories/GHSA-q768-x9m6-m9qp
Nodejs ‘undici’ vulnerable to CRLF Injection via Content-Type - https://github.com/advisories/GHSA-f772-66g8-q5h3
`undici.request` vulnerable to SSRF using absolute URL on `pathname` - https://github.com/advisories/GHSA-8qr4-xgw6-wmr3
Regular Expression Denial of Service in Headers - https://github.com/advisories/GHSA-r6ch-mqf9-qc9w
CRLF Injection in Nodejs ‘undici’ via host - https://github.com/advisories/GHSA-5r9g-qh6m-jxff
Undici's cookie header not cleared on cross-origin redirect in fetch - https://github.com/advisories/GHSA-wqq4-5wpv-mx2g
Undici's fetch with integrity option is too lax when algorithm is specified but hash value is in incorrect - https://github.com/advisories/GHSA-9qxr-qj54-h672
Undici proxy-authorization header not cleared on cross-origin redirect in fetch - https://github.com/advisories/GHSA-3787-6prv-h9w3
Use of Insufficiently Random Values in undici - https://github.com/advisories/GHSA-c76h-2ccp-4975
Undici's Proxy-Authorization header not cleared on cross-origin redirect for dispatch, request, stream, pipeline - https://github.com/advisories/GHSA-m4v8-wqvr-p9f7
undici Denial of Service attack via bad certificate data - https://github.com/advisories/GHSA-cxrh-j4jr-qwg3
fix available via `npm audit fix`
node_modules/undici
  fastify-reply-from  0.5.0 - 6.6.0
  Depends on vulnerable versions of undici
  node_modules/fastify-reply-from

// after audit fix

# npm audit report

fast-jwt  <=5.0.5
Severity: moderate
JWT Algorithm Confusion - https://github.com/advisories/GHSA-c2ff-88x2-x9pg
Fast-JWT Improperly Validates iss Claims - https://github.com/advisories/GHSA-gm45-q3v2-6cf8
No fix available
node_modules/fast-jwt
  fastify-jwt  *
  Depends on vulnerable versions of fast-jwt
  node_modules/fastify-jwt
  node_modules/fastify-jwt-deprecated

fastify-http-proxy  *
Depends on vulnerable versions of fastify-reply-from
Depends on vulnerable versions of fastify-reply-from - null
No fix available
node_modules/fastify-http-proxy
node_modules/fastify-http-proxy-deprecated


fastify-reply-from  *
Depends on vulnerable versions of undici - null
Depends on vulnerable versions of undici
No fix available
node_modules/fastify-reply-from
node_modules/fastify-reply-from-deprecated

undici  <=5.28.5
Severity: high
undici before v5.8.0 vulnerable to CRLF injection in request headers - https://github.com/advisories/GHSA-3cvr-822r-rqcc
ProxyAgent vulnerable to MITM - https://github.com/advisories/GHSA-pgw7-wx7w-2w33
undici before v5.8.0 vulnerable to uncleared cookies on cross-host / cross-origin redirect - https://github.com/advisories/GHSA-q768-x9m6-m9qp
Nodejs ‘undici’ vulnerable to CRLF Injection via Content-Type - https://github.com/advisories/GHSA-f772-66g8-q5h3
`undici.request` vulnerable to SSRF using absolute URL on `pathname` - https://github.com/advisories/GHSA-8qr4-xgw6-wmr3
Regular Expression Denial of Service in Headers - https://github.com/advisories/GHSA-r6ch-mqf9-qc9w
CRLF Injection in Nodejs ‘undici’ via host - https://github.com/advisories/GHSA-5r9g-qh6m-jxff
Undici's cookie header not cleared on cross-origin redirect in fetch - https://github.com/advisories/GHSA-wqq4-5wpv-mx2g
Undici's fetch with integrity option is too lax when algorithm is specified but hash value is in incorrect - https://github.com/advisories/GHSA-9qxr-qj54-h672
Undici proxy-authorization header not cleared on cross-origin redirect in fetch - https://github.com/advisories/GHSA-3787-6prv-h9w3
Use of Insufficiently Random Values in undici - https://github.com/advisories/GHSA-c76h-2ccp-4975
Undici's Proxy-Authorization header not cleared on cross-origin redirect for dispatch, request, stream, pipeline - https://github.com/advisories/GHSA-m4v8-wqvr-p9f7
undici Denial of Service attack via bad certificate data - https://github.com/advisories/GHSA-cxrh-j4jr-qwg3
No fix available
node_modules/undici

5 vulnerabilities (2 low, 2 moderate, 1 high)

Some issues need review, and may require choosing
a different dependency.

[Client]
   ↓ HTTPS
[NGINX (TLS, rate limiting, etc.)]
   ↓ HTTP (internal)
[Fastify API Gateway (auth, routing, proxy via undici/fetch)]
   ↓
[Microservices]

* https://developer.mozilla.org/en-US/docs/Web/API/Fetch_API/Using_Fetch
